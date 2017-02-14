/*
 * usb_host.h
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
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

#ifndef __TIZEN_USB_HOST_H__
#define __TIZEN_USB_HOST_H__

#include <stdint.h>
#include <tizen.h>

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Enumeration of an endpoint's direction.
 * @since_tizen 3.0
 */
typedef enum {
	USB_HOST_DIRECTION_IN,	/**< IN direction */
	USB_HOST_DIRECTION_OUT,	/**< OUT direction */
} usb_host_endpoint_direction_e;

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Enumeration of transfer type.
 * @since_tizen 3.0
 */
typedef enum {
	USB_HOST_TRANSFER_TYPE_CONTROL,		/**< Control transfer */
	USB_HOST_TRANSFER_TYPE_ISOCHRONOUS,	/**< Isochronous transfer */
	USB_HOST_TRANSFER_TYPE_BULK,		/**< Bulk transfer */
	USB_HOST_TRANSFER_TYPE_INTERRUPT,	/**< Interrupt transfer */
} usb_host_transfer_type_e;

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Enumeration of isochronous endpoint's synchronization type.
 * @since_tizen 3.0
 */
typedef enum {
	USB_HOST_ISO_SYNC_TYPE_NONE,	/**< No synchronization */
	USB_HOST_ISO_SYNC_TYPE_ASYNC,	/**< Asynchronous */
	USB_HOST_ISO_SYNC_TYPE_ADAPTIVE,/**< Adaptive */
	USB_HOST_ISO_SYNC_TYPE_SYNC,	/**< Synchronous */
} usb_host_iso_sync_type_e;

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Enumeration of an endpoint's usage type.
 * @since_tizen 3.0
 */
typedef enum {
	USB_HOST_USAGE_TYPE_DATA,	/**< Data endpoint */
	USB_HOST_USAGE_TYPE_FEEDBACK,	/**< Feedback endpoint */
	USB_HOST_USAGE_TYPE_IMPLICIT,	/**< Implicit feedback Data endpoint */
} usb_host_usage_type_e;

/**
 * @ingroup CAPI_USB_HOST_MODULE
 * @brief Enumeration of error codes reported by USB host API.
 * @since_tizen 3.0
 */
typedef enum {
	USB_HOST_ERROR_NONE = TIZEN_ERROR_NONE, /**< Successful */
	USB_HOST_ERROR_IO_ERROR = TIZEN_ERROR_IO_ERROR, /**< I/O error */
	USB_HOST_ERROR_INVALID_PARAMETER = TIZEN_ERROR_INVALID_PARAMETER, /**< Invalid parameter */
	USB_HOST_ERROR_PERMISSION_DENIED = TIZEN_ERROR_PERMISSION_DENIED, /**< Permission denied */
	USB_HOST_ERROR_NO_SUCH_DEVICE = TIZEN_ERROR_NO_SUCH_DEVICE, /**< No device */
	USB_HOST_ERROR_NOT_FOUND = TIZEN_ERROR_USB_HOST | 0x01, /**< Entity not found */
	USB_HOST_ERROR_RESOURCE_BUSY = TIZEN_ERROR_RESOURCE_BUSY, /**< Resource busy */
	USB_HOST_ERROR_TIMED_OUT = TIZEN_ERROR_TIMED_OUT, /**< Operation timed out */
	USB_HOST_ERROR_OVERFLOW = TIZEN_ERROR_USB_HOST | 0x02, /**< Overflow */
	USB_HOST_ERROR_DEVICE_NOT_OPENED = TIZEN_ERROR_USB_HOST | 0x03, /**< Device is not opened */
	USB_HOST_ERROR_BROKEN_PIPE = TIZEN_ERROR_BROKEN_PIPE, /**< Pipe error */
	USB_HOST_ERROR_INTERRUPTED_SYS_CALL = TIZEN_ERROR_INTERRUPTED_SYS_CALL, /**< System call interrupted */
	USB_HOST_ERROR_OUT_OF_MEMORY = TIZEN_ERROR_OUT_OF_MEMORY, /**< Insufficient memory */
	USB_HOST_ERROR_NOT_SUPPORTED = TIZEN_ERROR_NOT_SUPPORTED, /**< Operation not supported */
	USB_HOST_ERROR_UNKNOWN = TIZEN_ERROR_UNKNOWN, /**< Other error */
} usb_host_error_e;

/**
 * @ingroup CAPI_USB_HOST_MODULE
 * @brief Context handle to USB host.
 * @details This structure represents usb_host session.
 * Using own session allows to use this API independently.
 * For example calling usb_host_destroy() will not destroy resources
 * that are being used by another user of the library.
 *
 * To create session there is need to call usb_host_create(),
 * to destroy call usb_host_destroy(). Each session created by usb_host_create()
 * has to be destroyed using usb_host_destroy()
 * @since_tizen 3.0
 */
typedef struct usb_host_context_s *usb_host_context_h;

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Structure representing USB device.
 * @details This structure represents USB device found on USB bus.
 *
 * This can be obtained by usb_host_get_device_list() or usb_host_device_open_with_vid_pidi().
 * Some basic operations can be performed on closed device obtained by usb_host_device_list().
 * To perform any I/O operations the device must be opened by calling usb_host_device_open()
 * or usb_host_device_open_with_vid_pid().
 *
 * @since_tizen 3.0
 */
typedef struct usb_host_device_s *usb_host_device_h;

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief USB config handle.
 * @details This type represents USB device configuration. Device can have multiple configurations,
 * a configuration can have multiple interfaces. This handle can be obtained by
 * usb_host_device_get_config().
 * @since_tizen 3.0
 */
typedef struct usb_host_config_s *usb_host_config_h;

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief USB interface handle.
 * @details This type represents USB interface. An interface is a part of configuration and
 * can have multiple endpoints. This handle can be obtained by usb_host_config_get_interface().
 * @since_tizen 3.0
 */
typedef struct usb_host_interface_s *usb_host_interface_h;

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief USB endpoint handle.
 * @details This type represents USB endpoint. This handle can be obtained by
 * usb_host_interface_get_endpoint().
 * @since_tizen 3.0
 */
typedef struct usb_host_endpoint_s *usb_host_endpoint_h;

/* Library initialization and cleanup */

/**
 * @ingroup CAPI_USB_HOST_MODULE
 * @brief Initializes usb_host context.
 * @details This function must be called before any other function from this module.
 * @since_tizen 3.0
 * @remarks @a ctx should be destroyed by calling usb_host_destroy() when no longer needed.
 * @param[out] ctx Context pointer
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Successful
 * @post usb_host_destroy() should be called to free resources allocated for ctx by this function.
 */
int usb_host_create(usb_host_context_h *ctx);

/**
 * @ingroup CAPI_USB_HOST_MODULE
 * @brief Deinitializes usb_host context.
 * @details This function must be called after closing all devices
 * and before application close. It has to be called to clean
 * the memory used by library.
 * @since_tizen 3.0
 * @param[in] ctx Context to deinitialize
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Success
 * @pre Context must be initialized by usb_host_create().
 */
int usb_host_destroy(usb_host_context_h ctx);

/* Device handling and enumeration */

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets USB device list.
 * @details This function returns list of USB devices attached to system.
 * To free obtained device list usb_host_free_device_list() should be used, this
 * function can also unref devices. Do not unref device and then open it.
 *
 * All devices have reference counter. Functions usb_host_ref_device() and
 * usb_host_unref_device() are used to ref or unref device. When ref counter
 * reaches 0 device will be freed.
 * Devices reached by calling usb_host_get_device_list() have a reference count of
 * 1, and usb_host_free_device_list() can optionally decrease the reference count
 * on all devices in the list. usb_host_device_open() adds another reference which is
 * later destroyed by usb_host_device_close().
 *
 * @since_tizen 3.0
 * @param[in] ctx Context handle
 * @param[out] devs An array of devices
 * @param[out] length Number of devices
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Operation not supported
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Successful
 * @post @a devs must be freed with usb_host_free_device_list() when no longer needed.
 */
int usb_host_get_device_list(usb_host_context_h ctx, usb_host_device_h **devs, int *length);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Frees devices list.
 * @details This function needs to be called to free device list. This
 * function can also unref devices if unref_devices is set to non-zero value.
 * Do not unref device and then open it.
 * @since_tizen 3.0
 * @param[in] devs List of devices
 * @param[in] unref_devices Set to true to unreference devices, set to false to not unref
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Successful
 * @pre usb_host_get_device_list() must be called before using this function.
 */
int usb_host_free_device_list(usb_host_device_h *devs, bool unref_devices);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Refs a device.
 * @details Increment ref count of device.
 * @since_tizen 3.0
 * @param[in] dev Device to reference
 * @return 0 on success, error code otherwise
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Successful
 */
int usb_host_ref_device(usb_host_device_h dev);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Unrefs a device.
 * @details Decrements ref count of device. If ref count reaches zero,
 * device will be destroyed.
 * @since_tizen 3.0
 * @param[in] dev Device to unreference
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_unref_device(usb_host_device_h dev);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Opens a device.
 * @details This function opens a device, which allows performing operations on it
 * (including transfer operations and strings introspection).
 * @since_tizen 3.0
 * @param[in] dev Device to open
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_OUT_OF_MEMORY Memory allocation failure
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE There is no device connected
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED No proper permission to access device
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Operation not supported
 * @see usb_host_is_device_opened()
 */
int usb_host_device_open(usb_host_device_h dev);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Closes device.
 * @details Function should be called before usb_host_destroy().
 * It destroys reference that was added by usb_host_device_open().
 * @since_tizen 3.0
 * @param[in] dev Device that should be closed
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_DEVICE_NOT_OPENED If device is not opened
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Successful
 */
int usb_host_device_close(usb_host_device_h dev);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Opens device with valid idVendor and idProduct.
 * @details This function can be used to open device with known idVendor and
 * idProduct. If two or more devices have same vendor and product id only
 * first will be opened.
 * @since_tizen 3.0
 * @param[in] ctx Context
 * @param[in] vendor_id idVendor of connected device
 * @param[in] product_id idProduct of connected device
 * @param[out] device_handle Opened device handle
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_OUT_OF_MEMORY Insufficient memory
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE No device
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_open_with_vid_pid(usb_host_context_h ctx,
				  int vendor_id, int product_id, usb_host_device_h *device_handle);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets bus number.
 * @details Gets device bus number. This is number of the bus
 * that device is connected to.
 * @since_tizen 3.0
 * @param[in] dev Device handle
 * @param[out] bus_number Device bus number
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 */
int usb_host_device_get_bus_number(usb_host_device_h dev, int *bus_number);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets address.
 * @details Gets device address. This is address of device on the bus
 * that device is connected to.
 * @since_tizen 3.0
 * @param[in] dev Device
 * @param[out] device_address Device address
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 */
int usb_host_device_get_address(usb_host_device_h dev, int *device_address);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets list of port numbers.
 * @details Gets list of all port numbers from a device.
 * @since_tizen 3.0
 * @param[in] dev Device
 * @param[out] port_numbers Array to be filled with port numbers
 * @param[in] port_numbers_len Max length of array
 * @param[out] ports_count Number of all ports obtained from device
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_OUT_OF_MEMORY Insufficient memory
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 */
int usb_host_device_get_port_numbers(usb_host_device_h dev, int *port_numbers, int port_numbers_len, int *ports_count);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets a configuration.
 * @details Gets a USB configuration from a device.
 * @since_tizen 3.0
 * @remarks @a config must be freed with usb_host_config_destroy().
 * @param[in] dev Device
 * @param[in] config_index index of configuration to retrieve (counting from 0)
 * @param[out] config Output location for USB configuration
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_FOUND The configuration does not exist
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @post Returned configuration should be destroyed by usb_host_config_destroy()
 * when no longer needed.
 */
int usb_host_device_get_config(usb_host_device_h dev, int config_index, usb_host_config_h *config);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets an active config.
 * @details Gets handle to active configuration.
 * This function will return 0 value in config parameter :if device is unconfigured.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] config Handle to active configuration
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE the dev has been disconnected
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @post Obtained configuration should be destroyed by usb_host_config_destroy()
 * when no longer needed.
 */
int usb_host_get_active_config(usb_host_device_h dev, usb_host_config_h *config);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Sets a configuration.
 * @details Set active configuration for a device.
 * @since_tizen 3.0
 * @param[in] configuration Handle to configuration to be activated
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_FOUND Requested configuration does not exist
 * @retval #USB_HOST_ERROR_RESOURCE_BUSY Interfaces are currently claimed
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE The device has been disconnected
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_DEVICE_NOT_OPENED The device was not opened
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 */
int usb_host_set_config(usb_host_config_h configuration);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets USB specification release number.
 * @details Gets binary-coded decimal USB specification release number.
 * This value is equal to bcdUSB field of device descriptor. See USB specification
 * for more info.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] bcd_usb Bcd release number of USB
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 */
int usb_host_device_get_bcd_usb(usb_host_device_h dev, int *bcd_usb);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets device class.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] device_class Device class
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_class(usb_host_device_h dev, int *device_class);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets device sub class.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] subclass Device subclass
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_sub_class(usb_host_device_h dev, int *subclass);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets device protocol.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] protocol Device protocol
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_protocol(usb_host_device_h dev, int *protocol);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets maximum packet size for endpoint 0.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] max_packet_size Maximum size of single packet, in bytes
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_max_packet_size_0(usb_host_device_h dev, int *max_packet_size);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets vendor id.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] vendor_id Vendor id of @a dev
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_id_vendor(usb_host_device_h dev, int *vendor_id);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets product id.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] product_id Product id of @a dev
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_id_product(usb_host_device_h dev, int *product_id);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets device release number in binary-coded decimal.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] device_bcd Device release number
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_bcd_device(usb_host_device_h dev, int *device_bcd);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets number of configurations for given device.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] num_configurations Number of configurations for given device
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_device_get_num_configurations(usb_host_device_h dev, int *num_configurations);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Checks if device is opened.
 * @since_tizen 3.0
 * @param[in] dev A device
 * @param[out] is_opened True if device is opened, false otherwise
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_is_device_opened(usb_host_device_h dev, bool *is_opened);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets string describing device manufacturer, in ASCII.
 * @since_tizen 3.0
 * @param[in] dev A handle to opened device
 * @param[in, out] length Data buffer size/how much was actually used
 * @param[out] data Buffer to store string
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_OVERFLOW There was no space in buffer
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 * @pre dev must point to device opened by usb_host_device_open() or usb_host_device_open_with_vid_pid().
 */
int usb_host_device_get_manufacturer_str(usb_host_device_h dev, int *length, unsigned char *data);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets product string of device, in ASCII.
 * @since_tizen 3.0
 * @param[in] dev A handle to opened device
 * @param[in, out] length Data buffer size/how much was actually used
 * @param[out] data Buffer to store string
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_OVERFLOW There was no space in buffer
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 * @pre dev must point to device opened by usb_host_device_open() or usb_host_device_open_with_vid_pid().
 */
int usb_host_device_get_product_str(usb_host_device_h dev, int *length, unsigned char *data);

/**
 * @ingroup CAPI_USB_HOST_DEV_MODULE
 * @brief Gets serial number of a device, in ASCII.
 * @since_tizen 3.0
 * @param[in] dev A handle to opened device
 * @param[in, out] length Data buffer size/how much was actually used
 * @param[out] data Buffer to store string
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_OVERFLOW There was no space in buffer
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 * @pre dev must point to device opened by usb_host_device_open() or usb_host_device_open_with_vid_pid().
 */
int usb_host_device_get_serial_number_str(usb_host_device_h dev, int *length, unsigned char *data);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Gets number of interfaces for given configuration.
 * @since_tizen 3.0
 * @param[in] config A configuration
 * @param[out] num_interfaces Number of interfaces
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_config_get_num_interfaces(usb_host_config_h config, int *num_interfaces);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Checks if device is self-powered in given configuration.
 * @since_tizen 3.0
 * @param[in] config A configuration
 * @param[out] self_powered True if device is self-powered in given configuration,
 * false otherwise
 * @return 0 on success, negative error code otherwise
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 */
int usb_host_config_is_self_powered(usb_host_config_h config, bool *self_powered);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Checks if device in given configuration supports remote wakeup.
 * @since_tizen 3.0
 * @param[in] config A configuration
 * @param[out] remote_wakeup True if device supports remote wakeup in given configuration,
 * false otherwise
 * @return 0 on success, negative error code otherwise
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval @USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 */
int usb_host_config_support_remote_wakeup(usb_host_config_h config, bool *remote_wakeup);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Gets maximum power in given configuration, in mA.
 * @since_tizen 3.0
 * @param[in] config A configuration
 * @param[out] max_power Maximum power, in mA
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_config_get_max_power(usb_host_config_h config, int *max_power);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Gets string describing a configuration.
 * @since_tizen 3.0
 * @param[in] config A configuration
 * @param[in, out] length Data buffer size/how much was actually used
 * @param[out] data Buffer to store string
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_OVERFLOW There was no space in buffer
 * @retval #USB_HOST_ERROR_OUT_OF_MEMORY Out of memory
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @pre config must be configuration of device opened by usb_host_device_open() or
 * usb_host_device_open_with_vid_pid()
 */
int usb_host_device_get_config_str(usb_host_config_h config, int *length, unsigned char *data);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Gets an interface from configuration.
 * @details Gets a USB interface from configuration by its index.
 * @since_tizen 3.0
 * @param[in] config Configuration handle
 * @param[in] interface_index index of interface to retrieve (counting from 0)
 * @param[out] interface Interface handle
 * @remarks There is no need to destroy the @a interface handle. It is no longer valid
 * when config is destroyed.
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_FOUND Configuration does not exist
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 */
int usb_host_config_get_interface(usb_host_config_h config, int interface_index, usb_host_interface_h *interface);

/**
 * @ingroup CAPI_USB_HOST_CONFIG_MODULE
 * @brief Frees configuration.
 * @details Frees configuration obtained from usb_host_device_get_config().
 * @since_tizen 3.0
 * @param[in] config Configuration to free
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 * @pre config must be obtained by usb_host_device_get_config().
 */
int usb_host_config_destroy(usb_host_config_h config);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Claims interface.
 * @details Claims interface on a device.
 * To perform I/O operations on interface user has to claim it.
 * Remember to call usb_host_release_interface() when communication
 * with the device is finished.
 * @since_tizen 3.0
 * @param[in] interface The bInterfaceNumber of interface to claim
 * @param[in] force Set to true to auto detach kernel driver, set to false to not detach it
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_FOUND Requested interface does not exist
 * @retval #USB_HOST_ERROR_RESOURCE_BUSY Another program or driver has claimed the
 * interface
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE Device has been disconnected
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_DEVICE_NOT_OPENED The device was not opened
  */
int usb_host_claim_interface(usb_host_interface_h interface, bool force);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Releases interface.
 * @details Releases interface previously claimed by usb_host_claim_interface().
 * This is a blocking function.
 * @since_tizen 3.0
 * @param[in] interface The bInterfaceNumber of interface to release
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_FOUND Interface was not claimed
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE Device has been disconnected
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_DEVICE_NOT_OPENED The device was not opened
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_PERMISSION_DENIED Permission denied
 */
int usb_host_release_interface(usb_host_interface_h interface);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Gets number of given interface.
 * @since_tizen 3.0
 * @param[in] interface An interface
 * @param[out] number Number of given interface
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_interface_get_number(usb_host_interface_h interface, int *number);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Gets number of endpoints in given interface.
 * @since_tizen 3.0
 * @param[in] interface An interface
 * @param[out] num_endpoints Number of endpoints in @a interface
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_interface_get_num_endpoints(usb_host_interface_h interface, int *num_endpoints);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Gets an endpoint from interface.
 * @details Get a USB endpoint from interface by its index.
 * @since_tizen 3.0
 * @param[in] interface Interface handle
 * @param[in] ep_index index of endpoint to retrieve (counting from 0)
 * @param[out] ep Endpoint handle
 * @remarks @a ep handle is no longer valid when config will be destroyed. There is no need to destroy it,
 * it is done automatically when the configuration is destroyed.
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_interface_get_endpoint(usb_host_interface_h interface, int ep_index,
		usb_host_endpoint_h *ep);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Sets alternative setting for interface.
 * @since_tizen 3.0
 * @param[in] interface Interface handle
 * @param[in] altsetting Index of new alternative setting for given interface
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_interface_set_altsetting(usb_host_interface_h interface, int altsetting);

/**
 * @ingroup CAPI_USB_HOST_INTERFACE_MODULE
 * @brief Gets string describing an interface.
 * @since_tizen 3.0
 * @param[in] interface An interface
 * @param[in, out] length Data buffer size/how much was actually used
 * @param[out] data Buffer to store string
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_OVERFLOW There was no space in buffer
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @pre device which interface is part of must be opened by usb_host_device_open() or
 * usb_host_device_open_with_vid_pid()
 */
int usb_host_interface_get_str(usb_host_interface_h interface, int *length,
		unsigned char *data);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets number of given endpoint.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] number Number of given endpoint
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_number(usb_host_endpoint_h ep, int *number);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets direction of an endpoint.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] direction Direction of endpoint (a value from enum #usb_host_endpoint_direction_e)
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_direction(usb_host_endpoint_h ep, usb_host_endpoint_direction_e *direction);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets transfer type of given endpoint.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] transfer_type Transfer type (a value from enum #usb_host_transfer_type_e)
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_transfer_type(usb_host_endpoint_h ep, usb_host_transfer_type_e *transfer_type);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets synchronization type of given endpoint.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] synch_type Synch type (a value from enum #usb_host_iso_sync_type_e)
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_synch_type(usb_host_endpoint_h ep, usb_host_iso_sync_type_e *synch_type);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets usage type of given endpoint.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] usage_type Usage type (a value from enum #usb_host_usage_type_e)
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_usage_type(usb_host_endpoint_h ep, usb_host_usage_type_e *usage_type);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets max packet size of given endpoint.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] max_packet_size Max packet size, in bytes
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_max_packet_size(usb_host_endpoint_h ep, int *max_packet_size);

/**
 * @ingroup CAPI_USB_HOST_ENDPOINT_MODULE
 * @brief Gets interval for polling endpoint for data transfers.
 * @since_tizen 3.0
 * @param[in] ep An endpoint
 * @param[out] interval Interval for polling, in frame counts (refer to USB protocol specification)
 * @return 0 on success, otherwise a negative error value
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 */
int usb_host_endpoint_get_interval(usb_host_endpoint_h ep, int *interval);

/* sync IO */

/**
 * @ingroup CAPI_USB_HOST_SYNCIO_MODULE
 * @brief Performs USB control transfer.
 * @details For more explanation about the values please refer to USB protocol specification
 * @since_tizen 3.0
 * @remarks The wValue, wIndex and wLength fields values should be given in host-endian
 * byte order.
 * @param[in] dev Device handle
 * @param[in] bm_request_type bmRequestType type field for the setup packet
 * @param[in] b_request bRequest field for the setup packet
 * @param[in] w_value wValue field for the setup packet
 * @param[in] w_index wIndex field for the setup packet
 * @param[in] data Suitably-sized data buffer for either input or output
 * (depending on direction bits within bmRequestType)
 * @param[in] w_length wLength field for the setup packet. The data buffer should
 * be at least this size
 * @param[in] timeout Timeout (in milliseconds) that this function should wait
 * before giving up due to no response being received. For an unlimited
 * @param[out] transferred Number of transferred bytes
 * timeout, 0 value should be used.
 * @return  0 on success, negative error code otherwise
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_TIMED_OUT Transfer timed out
 * @retval #USB_HOST_ERROR_BROKEN_PIPE Control request was not supported by the device
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE The device has been disconnected
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_DEVICE_NOT_OPENED The device was not opened
 * @retval #USB_HOST_ERROR_OVERFLOW Device offered more data
 * @pre dev must point to device opened by usb_host_device_open() or usb_host_device_open_with_vid_pid()
 */
int usb_host_control_transfer(usb_host_device_h dev,
	uint8_t bm_request_type, uint8_t b_request, uint16_t w_value, uint16_t w_index,
	unsigned char *data, uint16_t w_length, unsigned int timeout, int *transferred);

/**
 * @ingroup CAPI_USB_HOST_SYNCIO_MODULE
 * @brief Performs transfer on given endpoint.
 * @details Performs a USB transfer on given endpoint. Direction of transfer is
 * determined by the endpoint.
 * @since_tizen 3.0
 * @param[in] ep Endpoint handle
 * @param[in] data Suitably-sized data buffer for either input or output
 * (depending on endpoint)
 * @param[in] length For writes, the number of bytes from data to be sent, for
 * reads the maximum number of bytes to receive into the data buffer
 * @param[out] transferred number of bytes actually transferred
 * @param[in] timeout Timeout (in milliseconds) that this function should wait
 * before giving up due to no response being received (for an unlimited
 * timeout 0 value should be used)
 * @return 0 on success (and populates @a transferred), negative error code on error
 * @retval #USB_HOST_ERROR_NONE Successful
 * @retval #USB_HOST_ERROR_TIMED_OUT Transfer timed out
 * @retval #USB_HOST_ERROR_BROKEN_PIPE Endpoint halted
 * @retval #USB_HOST_ERROR_OVERFLOW Device offered more data
 * @retval #USB_HOST_ERROR_NO_SUCH_DEVICE Device has been disconnected
 * @retval #USB_HOST_ERROR_INVALID_PARAMETER Invalid parameter was passed
 * @retval #USB_HOST_ERROR_NOT_SUPPORTED Not supported
 * @retval #USB_HOST_ERROR_DEVICE_NOT_OPENED The device was not opened
 * @pre ep must be a valid endpoint received from usb_host_interface_get_endpoint().
 * @pre ep must be an endpoint of device opened by usb_host_device_open() or
 * usb_host_device_open_with_vid_pid().
 */
int usb_host_transfer(usb_host_endpoint_h ep, unsigned char *data, int length,
		int *transferred, unsigned int timeout);

#ifdef __cplusplus
}
#endif

#endif /* __TIZEN_USB_HOST_H__ */
