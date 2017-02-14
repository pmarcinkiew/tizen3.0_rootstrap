/*
 *  Copyright (c) 2016 Samsung Electronics Co., Ltd All Rights Reserved
 *
 *  Contact: Krzysztof Jackiewicz <k.jackiewicz@samsung.com>
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License
 */

/**
 * @file   yaca_seal.h
 * @brief  Advanced API for the asymmetric encryption.
 *
 * @details  Seal does more than just encrypt. It first generates the encryption key and
 *           Initialization Vector, then encrypts whole message using this key
 *           (and selected symmetric algorithm).
 *           Finally it encrypts symmetric key with public key.
 */

#ifndef YACA_SEAL_H
#define YACA_SEAL_H

#include <stddef.h>
#include <yaca_types.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @addtogroup CAPI_YACA_ENCRYPTION_MODULE
 * @{
 */

/**
 * @brief  Initializes an asymmetric encryption context and generates
 *         symmetric key and Initialization Vector.
 *
 * @remarks  Generated symmetric key is encrypted with public key,
 *           so can be only used with yaca_open_initialize(). It can be exported,
 *           but after import it can be only used with yaca_open_initialize() as well.
 *
 * @remarks  The @a ctx should be released using yaca_context_destroy().
 *
 * @remarks  The @a pub_key must be #YACA_KEY_TYPE_RSA_PUB.
 *
 * @remarks  The @a sym_key_bit_len must be at least 88 bits shorter than the @a pub_key bit length.
 *
 * @remarks  The @a sym_key should be released using yaca_key_destroy().
 *
 * @remarks  The @a iv should be released using yaca_key_destroy().
 *
 * @since_tizen 3.0
 *
 * @param[out] ctx              Newly created context
 * @param[in]  pub_key          Public key of the peer that will receive the encrypted data
 * @param[in]  algo             Symmetric algorithm that will be used
 * @param[in]  bcm              Block chaining mode for the symmetric algorithm
 * @param[in]  sym_key_bit_len  Symmetric key length (in bits) that will be generated
 * @param[out] sym_key          Generated symmetric key that will be used,
 *                              it is encrypted with peer's public key
 * @param[out] iv               Generated Initialization Vector that will be used
 *
 * @return #YACA_ERROR_NONE on success, negative on error
 * @retval #YACA_ERROR_NONE Successful
 * @retval #YACA_ERROR_INVALID_PARAMETER Required parameters have incorrect values (NULL,
 *                                       invalid @a algo, @a bcm, @a sym_key_bit_len or @a pub_key)
 * @retval #YACA_ERROR_OUT_OF_MEMORY Out of memory error
 * @retval #YACA_ERROR_INTERNAL Internal error
 *
 * @see #yaca_encrypt_algorithm_e
 * @see #yaca_block_cipher_mode_e
 * @see #yaca_key_bit_length_e
 * @see yaca_seal_update()
 * @see yaca_seal_finalize()
 * @see yaca_open_initialize()
 * @see yaca_key_destroy()
 * @see yaca_context_destroy()
 */
int yaca_seal_initialize(yaca_context_h *ctx,
						 const yaca_key_h pub_key,
						 yaca_encrypt_algorithm_e algo,
						 yaca_block_cipher_mode_e bcm,
						 size_t sym_key_bit_len,
						 yaca_key_h *sym_key,
						 yaca_key_h *iv);

/**
 * @brief  Encrypts piece of the data.
 *
 * @since_tizen 3.0
 *
 * @param[in,out] ctx             Context created by yaca_seal_initialize()
 * @param[in]     plaintext       Plaintext to be encrypted
 * @param[in]     plaintext_len   Length of the plaintext
 * @param[out]    ciphertext      Buffer for the encrypted data
 *                                (must be allocated by client, see yaca_context_get_output_length())
 * @param[out]    ciphertext_len  Length of the encrypted data,
 *                                actual number of bytes written will be returned here
 *
 * @return #YACA_ERROR_NONE on success, negative on error
 * @retval #YACA_ERROR_NONE Successful
 * @retval #YACA_ERROR_INVALID_PARAMETER Required parameters have incorrect values (NULL, 0,
 *                                       invalid @a ctx)
 * @retval #YACA_ERROR_INTERNAL Internal error
 *
 * @see yaca_seal_initialize()
 * @see yaca_seal_finalize()
 * @see yaca_context_get_output_length()
 */
int yaca_seal_update(yaca_context_h ctx,
					 const char *plaintext,
					 size_t plaintext_len,
					 char *ciphertext,
					 size_t *ciphertext_len);

/**
 * @brief  Encrypts the final piece of the data.
 *
 * @remarks  Skipping yaca_seal_update() and calling only yaca_seal_finalize() will produce an
 *           encryption of an empty message.
 *
 * @since_tizen 3.0
 *
 * @param[in,out] ctx             A valid seal context
 * @param[out]    ciphertext      Final piece of the encrypted data
 *                                (must be allocated by client, see yaca_context_get_output_length())
 * @param[out]    ciphertext_len  Length of the final piece,
 *                                actual number of bytes written will be returned here
 *
 * @return #YACA_ERROR_NONE on success, negative on error
 * @retval #YACA_ERROR_NONE Successful
 * @retval #YACA_ERROR_INVALID_PARAMETER Required parameters have incorrect values (NULL,
 *                                       invalid @a ctx)
 * @retval #YACA_ERROR_INTERNAL Internal error
 *
 * @see yaca_seal_initialize()
 * @see yaca_seal_update()
 * @see yaca_context_get_output_length()
 */
int yaca_seal_finalize(yaca_context_h ctx,
					   char *ciphertext,
					   size_t *ciphertext_len);

/**
 * @brief  Initializes an asymmetric decryption context.
 *
 * @since_tizen 3.0
 *
 * @remarks  The @a ctx should be released using yaca_context_destroy().
 *
 * @remarks  The @a prv_key must be #YACA_KEY_TYPE_RSA_PRIV.
 *
 * @param[out] ctx              Newly created context
 * @param[in]  prv_key          Private key, part of the pair that was used for the encryption
 * @param[in]  algo             Symmetric algorithm that was used for the encryption
 * @param[in]  bcm              Block chaining mode for the symmetric algorithm
 * @param[in]  sym_key_bit_len  Symmetric key length (in bits) that was used for the encryption
 * @param[in]  sym_key          Symmetric key, encrypted with the public key,
 *                              that was used to encrypt the data
 * @param[in]  iv               Initialization Vector that was used for the encryption
 *
 * @return #YACA_ERROR_NONE on success, negative on error
 * @retval #YACA_ERROR_NONE Successful
 * @retval #YACA_ERROR_INVALID_PARAMETER Required parameters have incorrect values (NULL, invalid
 *                                       @a algo, @a bcm, @a sym_key_bit_len, @a prv_key,
 *                                       @a sym_key or @a iv)
 * @retval #YACA_ERROR_OUT_OF_MEMORY Out of memory error
 * @retval #YACA_ERROR_INTERNAL Internal error
 *
 * @see #yaca_encrypt_algorithm_e
 * @see #yaca_block_cipher_mode_e
 * @see #yaca_key_bit_length_e
 * @see yaca_open_update()
 * @see yaca_open_finalize()
 * @see yaca_context_destroy()
 */
int yaca_open_initialize(yaca_context_h *ctx,
						 const yaca_key_h prv_key,
						 yaca_encrypt_algorithm_e algo,
						 yaca_block_cipher_mode_e bcm,
						 size_t sym_key_bit_len,
						 const yaca_key_h sym_key,
						 const yaca_key_h iv);

/**
 * @brief  Decrypts piece of the data.
 *
 * @since_tizen 3.0
 *
 * @param[in,out] ctx             Context created by yaca_open_initialize()
 * @param[in]     ciphertext      Ciphertext to be decrypted
 * @param[in]     ciphertext_len  Length of the ciphertext
 * @param[out]    plaintext       Buffer for the decrypted data
 *                                (must be allocated by client, see yaca_context_get_output_length())
 * @param[out]    plaintext_len   Length of the decrypted data,
 *                                actual number of bytes written will be returned here
 *
 * @return #YACA_ERROR_NONE on success, negative on error
 * @retval #YACA_ERROR_NONE Successful
 * @retval #YACA_ERROR_INVALID_PARAMETER Required parameters have incorrect values (NULL, 0,
 *                                       invalid @a ctx), wrong #YACA_PROPERTY_CCM_AAD or
 *                                       wrong #YACA_PROPERTY_CCM_TAG was used
 * @retval #YACA_ERROR_INTERNAL Internal error
 *
 * @see yaca_open_initialize()
 * @see yaca_open_finalize()
 * @see yaca_context_get_output_length()
 */
int yaca_open_update(yaca_context_h ctx,
					 const char *ciphertext,
					 size_t ciphertext_len,
					 char *plaintext,
					 size_t *plaintext_len);

/**
 * @brief  Decrypts last chunk of sealed message.
 *
 * @remarks  Skipping yaca_open_update() and calling only yaca_open_finalize() will produce a
 *           decryption of an empty ciphertext.
 *
 * @since_tizen 3.0
 *
 * @param[in,out] ctx            A valid open context
 * @param[out]    plaintext      Final piece of the decrypted data
 *                               (must be allocated by client, see yaca_context_get_output_length())
 * @param[out]    plaintext_len  Length of the final piece,
 *                               actual number of bytes written will be returned here
 *
 * @return #YACA_ERROR_NONE on success, negative on error
 * @retval #YACA_ERROR_NONE Successful
 * @retval #YACA_ERROR_INVALID_PARAMETER Required parameters have incorrect values (NULL,
 *                                       invalid @a ctx), wrong #YACA_PROPERTY_GCM_AAD or
 *                                       wrong #YACA_PROPERTY_GCM_TAG was used
 * @retval #YACA_ERROR_INTERNAL Internal error
 *
 * @see yaca_open_initialize()
 * @see yaca_open_update()
 * @see yaca_context_get_output_length()
 */
int yaca_open_finalize(yaca_context_h ctx,
					   char *plaintext,
					   size_t *plaintext_len);

/**
 * @}
 */

#ifdef __cplusplus
} /* extern */
#endif

#endif /* YACA_SEAL_H */
