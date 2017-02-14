/*
 * Copyright (c) 2012, 2013 Samsung Electronics Co., Ltd.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __TIZEN_NET_DNSSD_H__
#define __TIZEN_NET_DNSSD_H__

#include <tizen.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef TIZEN_ERROR_DNSSD
#define TIZEN_ERROR_DNSSD -0x01CA0000
#endif


/**
 * @addtogroup CAPI_NETWORK_DNSSD_MODULE
 * @{
 */

/**
 * @brief Enumeration for Network Service Discovery DNSSD error code.
 * @since_tizen 3.0
 */
typedef enum {
	DNSSD_ERROR_NONE = TIZEN_ERROR_NONE, /**< Successful */
	DNSSD_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY, /**< Out of memory*/
	DNSSD_ERROR_INVALID_OPERATION = TIZEN_ERROR_INVALID_OPERATION, /**< Invalid operation */
	DNSSD_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid function parameter*/
	DNSSD_ERROR_NOT_SUPPORTED = TIZEN_ERROR_NOT_SUPPORTED, /**< Not supported */
	DNSSD_ERROR_NOT_INITIALIZED = TIZEN_ERROR_DNSSD | 0x01, /**< Not Initialized */
	DNSSD_ERROR_ALREADY_REGISTERED = TIZEN_ERROR_DNSSD | 0x02, /**< Already registered */
	DNSSD_ERROR_NAME_CONFLICT = TIZEN_ERROR_DNSSD | 0x03, /**< Name conflict */
	DNSSD_ERROR_SERVICE_NOT_RUNNING = TIZEN_ERROR_DNSSD | 0x04,	/**< Background daemon not running */
	DNSSD_ERROR_SERVICE_NOT_FOUND = TIZEN_ERROR_DNSSD | 0x05, /**<  Service not found */
	DNSSD_ERROR_OPERATION_FAILED = TIZEN_ERROR_DNSSD | 0x06, /**< Operation failed */
} dnssd_error_e;


/**
 * @brief Enumeration for Network Service Discovery DNSSD browse state.
 * @since_tizen 3.0
 */
typedef enum {
	DNSSD_SERVICE_STATE_AVAILABLE, /**<Available DNS-SD service found */
	DNSSD_SERVICE_STATE_UNAVAILABLE, /**<DNS-SD service not available */
	DNSSD_SERVICE_STATE_NAME_LOOKUP_FAILED, /**<Lookup failure for service name */
	DNSSD_SERVICE_STATE_HOST_NAME_LOOKUP_FAILED, /**<Lookup failure for host name and port number */
	DNSSD_SERVICE_STATE_ADDRESS_LOOKUP_FAILED, /**<Lookup failure for IP address */
} dnssd_service_state_e;


/**
 * @brief The DNSSD service handle.
 * @since_tizen 3.0
 */
typedef unsigned int dnssd_service_h;


/**
 * @brief The DNSSD Browser handle.
 * @since_tizen 3.0
 */
typedef unsigned int dnssd_browser_h;


/**
 * @brief Called when the registration of DNSSD service is finished.
 * @since_tizen 3.0
 * @param[in] result The result of registration.\n
 *                   #DNSSD_ERROR_NONE Successful\n
 *                   #DNSSD_ERROR_NAME_CONFLICT Name Conflict\n
 *                   #DNSSD_ERROR_ALREADY_REGISTERED Already Registered
 * @param[in] local_service The DNSSD local service handle
 * @param[in] user_data The user data passed from the request function
 * @see dnssd_register_local_service()
 */
typedef void (*dnssd_registered_cb) (dnssd_error_e result, dnssd_service_h local_service, void *user_data);


/**
 * @brief Called when a DNSSD service is found.
 * @details remote_service is valid only when service_state is
 *          DNSSD_SERVICE_STATE_AVAILABLE or DNSSD_SERVICE_STATE_UNAVAILABLE.
 *          In case of service_state DNSSD_SERVICE_STATE_UNAVAILABLE, application
 *          can only use dnssd_service_get_type() and dnssd_service_get_name().
 *          Other get functions can only be used when service_state is
 *          DNSSD_SERVICE_STATE_AVAILABLE.
 * @since_tizen 3.0
 * @param[in] service_state The DNSSD service state of remote service
 * @param[in] remote_service The DNSSD remote service handle
 * @param[in] user_data The user data passed from the request function
 * @see dnssd_start_browsing_service()
 */
typedef void (*dnssd_found_cb) (dnssd_service_state_e service_state, dnssd_service_h remote_service, void *user_data);


/**
 * @brief Initializes DNSSD.
 * @since_tizen 3.0
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 */
int dnssd_initialize(void);


/**
 * @brief Deinitializes DNSSD.
 * @since_tizen 3.0
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_INVALID_OPERATION Invalid Operation
 * @pre DNS-SD service must be initialized by dnssd_initialize().
 */
int dnssd_deinitialize(void);


/**
 * @brief Creates a DNSSD local service handle.
 * @since_tizen 3.0
 * @remarks You must release @a dnssd_service using dnssd_destroy_local_service().
 * @param[in] service_type The DNSSD service type. It is expressed as type
 *            followed by protocol, separated by a dot(e.g. "_ftp._tcp"). It
 *            must begin with an underscore, followed by 1-15 characters which
 *            may be letters, digits, or hyphens. The transport protocol must be
 *            "_tcp" or "_udp". New service types should be registered at
 *            http://www.dns-sd.org/ServiceTypes.html.
 * @param[out] dnssd_service The DNSSD local handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_destroy_local_service()
 * @pre This API needs dnssd_initialize() before use
 */
int dnssd_create_local_service(const char *service_type, dnssd_service_h *dnssd_service);


/**
 * @brief Destroys the DNSSD local service handle.
 * @details Destroying a local service doesn't deregister local service. If
 *          local service was registered using dnssd_register_local_service(),
 *          then it must be deregistered using dnssd_deregister_local_service()
 *          before destroying the local service.
 * @since_tizen 3.0
 * @remarks You must destroy only local services created using dnssd_create_local_service().
 * @param[in] dnssd_service The DNSSD local service handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_destroy_local_service(dnssd_service_h dnssd_service);


/**
 * @brief Sets the name of DNSSD local service.
 * @details Application should set name after creating local service using
 *          dnssd_create_local_service() and before registering the local
 *          service using dnssd_register_local_service().
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] service_name The name of DNSSD local service
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_service_set_name(dnssd_service_h local_service, const char *service_name);


/**
 * @brief Sets the port number of DNSSD local service.
 * @details Application should set port after creating local service using
 *          dnssd_create_local_service() and before registering the local
 *          service using dnssd_register_local_service().
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] port The port number of DNSSD local service
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_service_set_port(dnssd_service_h local_service, int port);


/**
 * @brief Adds the TXT record.
 * @details TXT record should be added after registering local service using
 *          dnssd_register_local_service(). TXT record gives additional
 *          information about the service. Some services discovered via
 *          dnssd_start_browsing_service() may need more than just IP address
 *          and port number to completely identify the service instance. For
 *          example, A web server typically has multiple pages, each identified
 *          by its own URL. So additional data is stored in a TXT record. Check
 *          Section 6 of http://files.dns-sd.org/draft-cheshire-dnsext-dns-sd.txt
 *          for details. TXT record of known service types can be found at
 *          http://www.dns-sd.org/ServiceTypes.html. TXT record is stored in a
 *          structured form using key/value pairs.
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] key The key of the TXT record. A null-terminated string which only
 *                contains printable ASCII values (0x20-0x7E), excluding '=' (0x3D).
 *                Keys should be 9 characters or fewer excluding NULL. Keys are case
 *                insensitivie. Keys for known service types can be found at
 *                http://www.dns-sd.org/ServiceTypes.html. For details, see section
 *                6.4 of http://files.dns-sd.org/draft-cheshire-dnsext-dns-sd.txt.
 * @param[in] length The length of the value of the TXT record in bytes. The
 *                   total size of a typical DNS-SD TXT record is intended to be small
 *                   (upto 200 bytes). For details, see section 6.2 of
 *                   http://files.dns-sd.org/draft-cheshire-dnsext-dns-sd.txt
 * @param[in] value The value of the TXT record. It can be any binary value. For
 *                  value that represents textual data, UTF-8 is STRONGLY recommended.
 *                  For value that represents textual data, value_length should NOT
 *                  include the terminating null (if any) at the end of the string. If
 *                  NULL, then "key" will be added with no value. If non-NULL but
 *                  value_length is zero, then "key=" will be added with empty value.
 *                  For details see section 6.5 of
 *                  http://files.dns-sd.org/draft-cheshire-dnsext-dns-sd.txt
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_ALREADY_REGISTERED Already Registered
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_service_add_txt_record(dnssd_service_h local_service, const char *key, unsigned short length, const void *value);


/**
 * @brief Removes the TXT record.
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] key The key of the TXT record to be removed
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @see dnssd_service_add_txt_record()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_service_remove_txt_record(dnssd_service_h local_service, const char *key);


/**
 * @brief Sets/updates the DNS resource record.
 * @details If the resource record for the type has been previously added using
 *          dnssd_service_set_record(), then the record will be updated. DNS
 *          resource record can be set only after local_service is registered
 *          using dnssd_register_local_service(). Data is added using
 *          dnssd_service_add_txt_record() and then obtained using
 *          dnssd_service_get_all_txt_record() to pass here.
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] type The resource record type. For details see, RFC 1035 and RFC 2782
 * @param[in] length The length of the resource record in bytes
 * @param[in] data The data contained in resource record to be added
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_OPERATION_FAILED Operation failed
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_ALREADY_REGISTERED Already Registered
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_service_set_record(dnssd_service_h local_service, unsigned short type, unsigned short length, const void *data);


/**
 * @brief Unsets the DNS resource record. DNS resource record for the given type
 *        must be set using dnssd_service_set_record().
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] type The resource record type. For details, see RFC 1035 and RFC 2782
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_OPERATION_FAILED Operation failed
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_service_unset_record(dnssd_service_h local_service, unsigned short type);


/**
 * @brief Registers the DNSSD local service for publishing.
 * @since_tizen 3.0
 * @remarks You must pass only local services created using dnssd_create_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @param[in] register_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_OPERATION_FAILED Operation failed
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @pre This API needs dnssd_create_local_service() before use.
 */
int dnssd_register_local_service(dnssd_service_h local_service, dnssd_registered_cb register_cb, void *user_data);


/**
 * @brief Deregisters the DNSSD local service.
 * @since_tizen 3.0
 * @remarks You must pass only local services registered using dnssd_register_local_service().
 * @param[in] local_service The DNSSD local service handle
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @see dnssd_create_local_service()
 * @see dnssd_register_local_service()
 * @pre This API needs dnssd_register_local_service() before use.
 */
int dnssd_deregister_local_service(dnssd_service_h local_service);


/**
 * @brief Starts browsing the DNSSD remote service.
 * @details found_cb would be called only if there are any services available of
 *          service_type provided in the argument. Application will keep
 *          browsing for available/unavailable services until it calls
 *          dnssd_stop_browsing_service().
 * @since_tizen 3.0
 * @param[in] service_type The DNSSD service type to browse. It is expressed
 *                         as type followed by protocol, separated by a dot(e.g. "_ftp._tcp").
 *                         It must begin with an underscore, followed by 1-15 characters
 *                         which may be letters, digits, or hyphens. The transport protocol
 *                         must be "_tcp" or "_udp". New service types should be registered
 *                         at http://www.dns-sd.org/ServiceTypes.html
 * @param[out] dnssd_service The DNSSD browse service handle
 * @param[in] found_cb The callback function to be called
 * @param[in] user_data The user data passed to the callback function
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @pre This API needs dnssd_initialize() before use.
 */
int dnssd_start_browsing_service(const char *service_type, dnssd_browser_h *dnssd_service, dnssd_found_cb found_cb, void *user_data);


/**
 * @brief Stops browsing the DNSSD remote service.
 * @since_tizen 3.0
 * @param[in] dnssd_service The DNSSD browse service handle returned by
 *                          dnssd_start_browsing_service()
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 * @pre This API needs dnssd_start_browsing_service() before use.
 */
int dnssd_stop_browsing_service(dnssd_browser_h dnssd_service);


/**
 * @brief Gets the type of DNSSD local/remote service.
 * @since_tizen 3.0
 * @remarks You must release @a service_type using free().
 * @param[in] dnssd_service The DNSSD local/remote service handle
 * @param[out] service_type The type of DNSSD service. It is expressed as type
 *                          followed by protocol, separated by a dot(e.g. "_ftp._tcp"). It
 *                          must begin with an underscore, followed by 1-15 characters which
 *                          may be letters, digits, or hyphens. The transport protocol must be
 *                          "_tcp" or "_udp". New service types should be registered at
 *                          http://www.dns-sd.org/ServiceTypes.html
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 */
int dnssd_service_get_type(dnssd_service_h dnssd_service, char **service_type);


/**
 * @brief Gets the name of DNSSD local/remote service.
 * @since_tizen 3.0
 * @remarks You must release @a service_name using free().
 * @param[in] dnssd_service The DNSSD local/remote service handle
 * @param[out] service_name The name of DNSSD service
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 */
int dnssd_service_get_name(dnssd_service_h dnssd_service, char **service_name);


/**
 * @brief Gets the IP of DNSSD remote service.
 * @since_tizen 3.0
 * @remarks You must release @a ip_v4_address, @a ip_v6_address using free().
 * @param[in] dnssd_service The DNSSD remote service handle
 * @param[out] ip_v4_address The IP version 4 address of DNSSD service. If there
 *                           is no IPv4 Address, then it would contain NULL and should not be freed
 * @param[out] ip_v6_address The IP version 6 address of DNSSD service. If there
 *                           is no IPv6 Address, then it would contain NULL and should not be freed
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 */
int dnssd_service_get_ip(dnssd_service_h dnssd_service, char **ip_v4_address, char **ip_v6_address);


/**
 * @brief Gets the port number of DNSSD local/remote service.
 * @since_tizen 3.0
 * @param[in] dnssd_service The DNSSD service local/remote handle
 * @param[out] port The port number of DNSSD service
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 */
int dnssd_service_get_port(dnssd_service_h dnssd_service, int *port);


/**
 * @brief Gets the TXT record.
 * @details TXT record gives additional information about the service. Some
 *          services discovered via dnssd_start_browsing_service() may need
 *          more than just IP address and port number to completely identify
 *          the service instance. For example, a web server typically has
 *          multiple pages, each identified by its own URL. So additional data
 *          is stored in a TXT record. Check Section 6 of
 *          http://files.dns-sd.org/draft-cheshire-dnsext-dns-sd.txt for
 *          details. TXT record of known service types can be found at
 *          http://www.dns-sd.org/ServiceTypes.html. TXT record is stored in a
 *          structured form using key/value pairs.
 * @since_tizen 3.0
 * @remarks You must release @value using free().
 * @param[in] dnssd_service The DNSSD local/remote service handle
 * @param[out] length The length of the value of the TXT record in bytes
 * @param[out] value The value of the TXT record
 * @return @c 0 on success,
 *         otherwise negative error value
 * @retval #DNSSD_ERROR_NONE Successful
 * @retval #DNSSD_ERROR_INVALID_PARAMETER Invalid parameter
 * @retval #DNSSD_ERROR_NOT_SUPPORTED Not Supported
 * @retval #DNSSD_ERROR_OUT_OF_MEMORY Out of Memory
 * @retval #DNSSD_ERROR_SERVICE_NOT_RUNNING Service Not Running
 * @retval #DNSSD_ERROR_NOT_INITIALIZED Not Initialized
 */
int dnssd_service_get_all_txt_record(dnssd_service_h dnssd_service, unsigned short *length, void **value);


/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_NET_DNSSD_H__ */
