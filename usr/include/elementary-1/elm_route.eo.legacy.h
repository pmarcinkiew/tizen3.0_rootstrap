#ifndef _ELM_ROUTE_EO_LEGACY_H_
#define _ELM_ROUTE_EO_LEGACY_H_

#ifndef _ELM_ROUTE_EO_CLASS_TYPE
#define _ELM_ROUTE_EO_CLASS_TYPE

typedef Eo Elm_Route;

#endif

#ifndef _ELM_ROUTE_EO_TYPES
#define _ELM_ROUTE_EO_TYPES


#endif

/**
 * @internal
 *
 * @brief No description supplied by the EAPI.
 *
 * @param[in] emap
 *
 * @ingroup Elm_Route
 */
EAPI void elm_route_emap_set(Elm_Route *obj, void *emap);

/**
 * @internal
 *
 * @brief Get the minimum and maximum values along the
 * longitude.
 *
 * @note If only one value is needed, the other pointer can be passed as null.
 *
 * @param[out] min Pointer to store the minimum value.
 * @param[out] max Pointer to store the maximum value.
 *
 * @ingroup Elm_Route
 */
EAPI void elm_route_longitude_min_max_get(const Elm_Route *obj, double *min, double *max);

/**
 * @internal
 *
 * @brief Get the minimum and maximum values along the
 * latitude.
 *
 * @note If only one value is needed, the other pointer can be passed as null.
 *
 * @param[out] min Pointer to store the minimum value.
 * @param[out] max Pointer to store the maximum value.
 *
 * @ingroup Elm_Route
 */
EAPI void elm_route_latitude_min_max_get(const Elm_Route *obj, double *min, double *max);

#endif
