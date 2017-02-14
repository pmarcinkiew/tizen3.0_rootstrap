#ifndef _EVAS_COMMON_INTERFACE_EO_H_
#define _EVAS_COMMON_INTERFACE_EO_H_

#ifndef _EVAS_COMMON_INTERFACE_EO_CLASS_TYPE
#define _EVAS_COMMON_INTERFACE_EO_CLASS_TYPE

typedef Eo Evas_Common_Interface;

#endif

#ifndef _EVAS_COMMON_INTERFACE_EO_TYPES
#define _EVAS_COMMON_INTERFACE_EO_TYPES


#endif
#define EVAS_COMMON_INTERFACE_INTERFACE evas_common_interface_interface_get()

EAPI const Eo_Class *evas_common_interface_interface_get(void) EINA_CONST;

EOAPI Evas_Common_Interface * evas_common_evas_get(void);


#endif
