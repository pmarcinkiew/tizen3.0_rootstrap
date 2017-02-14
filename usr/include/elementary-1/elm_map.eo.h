#ifndef _ELM_MAP_EO_H_
#define _ELM_MAP_EO_H_

#ifndef _ELM_MAP_EO_CLASS_TYPE
#define _ELM_MAP_EO_CLASS_TYPE

typedef Eo Elm_Map;

#endif

#ifndef _ELM_MAP_EO_TYPES
#define _ELM_MAP_EO_TYPES


#endif
#define ELM_MAP_CLASS elm_map_class_get()

EAPI const Eo_Class *elm_map_class_get(void) EINA_CONST;

/**
 * @brief Set the zoom level of the map.
 *
 * This sets the zoom level.
 *
 * It will respect limits defined by @ref elm_obj_map_zoom_min_set and
 * @ref elm_obj_map_zoom_max_set.
 *
 * By default these values are 0 (world map) and 18 (maximum zoom).
 *
 * This function should be used when zoom mode is set to
 * #ELM_MAP_ZOOM_MODE_MANUAL. This is the default mode, and can be set with
 * @ref elm_obj_map_zoom_mode_set.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] zoom The zoom level.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_zoom_set(int zoom);

/**
 * @brief Get the zoom level of the map.
 *
 * This returns the current zoom level of the map object.
 *
 * Note that if you set the fill mode to other than #ELM_MAP_ZOOM_MODE_MANUAL
 * (which is the default), the zoom level may be changed at any time by the map
 * object itself to account for map size and map viewport size.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The zoom level.
 *
 * @ingroup Elm_Map
 */
EOAPI int  elm_obj_map_zoom_get(void);

/**
 * @brief Pause or unpause the map.
 *
 * This sets the paused state to on ($true) or off ($false) for map.
 *
 * The default is off.
 *
 * This will stop zooming using animation, changing zoom levels will change
 * instantly. This will stop any existing animations that are running.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] paused Use @c true to pause the map @c obj or @c false to unpause
 * it.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_paused_set(Eina_Bool paused);

/**
 * @brief Get a value whether map is paused or not.
 *
 * This gets the current paused state for the map object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Use @c true to pause the map @c obj or @c false to unpause it.
 *
 * @ingroup Elm_Map
 */
EOAPI Eina_Bool  elm_obj_map_paused_get(void);

/**
 * @brief Enable or disable mouse wheel to be used to zoom in / out the map.
 *
 * Wheel is enabled by default.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] disabled Use @c true to disable mouse wheel or @c false to enable
 * it.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_wheel_disabled_set(Eina_Bool disabled);

/**
 * @brief Get a value whether mouse wheel is enabled or not.
 *
 * Mouse wheel can be used for the user to zoom in or zoom out the map.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Use @c true to disable mouse wheel or @c false to enable it.
 *
 * @ingroup Elm_Map
 */
EOAPI Eina_Bool  elm_obj_map_wheel_disabled_get(void);

/**
 * @brief Set the minimum zoom of the source.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] zoom Minimum zoom value to be used.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_zoom_min_set(int zoom);

/**
 * @brief Get the minimum zoom of the source.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Minimum zoom value to be used.
 *
 * @ingroup Elm_Map
 */
EOAPI int  elm_obj_map_zoom_min_get(void);

/**
 * @brief Rotate the map.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] degree Angle from 0.0 to 360.0 to rotate around Z axis.
 * @param[in] cx Rotation's center horizontal position.
 * @param[in] cy Rotation's center vertical position.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_rotate_set(double degree, Evas_Coord cx, Evas_Coord cy);

/**
 * @brief Get the rotate degree of the map.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] degree Angle from 0.0 to 360.0 to rotate around Z axis.
 * @param[out] cx Rotation's center horizontal position.
 * @param[out] cy Rotation's center vertical position.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_rotate_get(double *degree, Evas_Coord *cx, Evas_Coord *cy);

/**
 * @brief Set the user agent used by the map object to access routing services.
 *
 * User agent is a client application implementing a network protocol used in
 * communications within a clientserver distributed computing system
 *
 * The @c user_agent identification string will transmitted in a header field
 * @c User-Agent.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] user_agent The user agent to be used by the map.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_user_agent_set(const char *user_agent);

/**
 * @brief Get the user agent used by the map object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The user agent to be used by the map.
 *
 * @ingroup Elm_Map
 */
EOAPI const char * elm_obj_map_user_agent_get(void);

/**
 * @brief Set the maximum zoom of the source.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] zoom Maximum zoom value to be used.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_zoom_max_set(int zoom);

/**
 * @brief Get the maximum zoom of the source.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return Maximum zoom value to be used.
 *
 * @ingroup Elm_Map
 */
EOAPI int  elm_obj_map_zoom_max_get(void);

/**
 * @brief Set the zoom mode used by the map object.
 *
 * This sets the zoom mode to manual or one of the automatic levels. Manual
 * (#ELM_MAP_ZOOM_MODE_MANUAL) means that zoom is set manually by
 * @ref elm_obj_map_zoom_mode_set and will stay at that level until changed by
 * code or until zoom mode is changed. This is the default mode.
 *
 * The Automatic modes will allow the map object to automatically adjust zoom
 * mode based on properties. #ELM_MAP_ZOOM_MODE_AUTO_FIT will adjust zoom so
 * the map fits inside the scroll frame with no pixels outside this area.
 * #ELM_MAP_ZOOM_MODE_AUTO_FILL will be similar but ensure no pixels within the
 * frame are left unfilled. Do not forget that the valid sizes are 2^zoom,
 * consequently the map may be smaller than the scroller view.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] mode The zoom mode of the map, being it one of
 * #ELM_MAP_ZOOM_MODE_MANUAL (default), #ELM_MAP_ZOOM_MODE_AUTO_FIT, or
 * #ELM_MAP_ZOOM_MODE_AUTO_FILL.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_zoom_mode_set(Elm_Map_Zoom_Mode mode);

/**
 * @brief Get the zoom mode used by the map object.
 *
 * This function returns the current zoom mode used by the ma object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The zoom mode of the map, being it one of #ELM_MAP_ZOOM_MODE_MANUAL
 * (default), #ELM_MAP_ZOOM_MODE_AUTO_FIT, or #ELM_MAP_ZOOM_MODE_AUTO_FILL.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Zoom_Mode  elm_obj_map_zoom_mode_get(void);

/**
 * @brief Get the current geographic coordinates of the map.
 *
 * This gets the current center coordinates of the map object. It can be set by
 * @ref elm_obj_map_region_bring_in and @ref elm_obj_map_region_show.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] lon Pointer to store longitude.
 * @param[out] lat Pointer to store latitude.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_region_get(double *lon, double *lat);

/**
 * @brief Return all overlays in the map object.
 *
 * This list includes group overlays also. So this can be changed dynamically
 * while zooming and panning.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The list of all overlays or @c null upon failure.
 *
 * @since 1.7
 *
 * @ingroup Elm_Map
 */
EOAPI Eina_List * elm_obj_map_overlays_get(void);

/**
 * @brief Get the information of tile load status.
 *
 * This gets the current tile loaded status for the map object.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[out] try_num Pointer to store number of tiles download requested.
 * @param[out] finish_num Pointer to store number of tiles successfully
 * downloaded.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_tile_load_status_get(int *try_num, int *finish_num);

/**
 * @brief Set the current source of the map for a specific type.
 *
 * Map widget retrieves tile images that composes the map from a web service.
 * This web service can be set with this method for #ELM_MAP_SOURCE_TYPE_TILE
 * type. A different service can return a different maps with different
 * information and it can use different zoom values.
 *
 * Map widget provides route data based on a external web service. This web
 * service can be set with this method for #ELM_MAP_SOURCE_TYPE_ROUTE type.
 *
 * Map widget also provide geoname data based on a external web service. This
 * web service can be set with this method for #ELM_MAP_SOURCE_TYPE_NAME type.
 *
 * The @c source_name need to match one of the names provided by
 * @ref elm_obj_map_sources_get.
 *
 * The current source can be get using @ref elm_obj_map_source_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] source_name The source to be used.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_source_set(Elm_Map_Source_Type type, const char *source_name);

/**
 * @brief Get the name of currently used source for a specific type.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] type Source type.
 *
 * @return The name of the source in use.
 *
 * @ingroup Elm_Map
 */
EOAPI const char * elm_obj_map_source_get(Elm_Map_Source_Type type);

/**
 * @brief Add a new route to the map object.
 *
 * A route will be traced by point on coordinates ($flat, @c flon) to point on
 * coordinates ($tlat, @c tlon), using the route service set with
 * @ref elm_obj_map_source_set.
 *
 * It will take @c type on consideration to define the route, depending if the
 * user will be walking or driving, the route may vary. One of
 * #ELM_MAP_ROUTE_TYPE_MOTOCAR, #ELM_MAP_ROUTE_TYPE_BICYCLE, or
 * #ELM_MAP_ROUTE_TYPE_FOOT need to be used.
 *
 * Another parameter is what the route should prioritize, the minor distance or
 * the less time to be spend on the route. So @c method should be one of
 * #ELM_MAP_ROUTE_METHOD_SHORTEST or #ELM_MAP_ROUTE_METHOD_FASTEST.
 *
 * Routes created with this method can be deleted with @ref elm_map_route_del
 * and distance can be get with @ref elm_map_route_distance_get.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] method The routing method, what should be prioritized.
 * @param[in] flon The start longitude.
 * @param[in] flat The start latitude.
 * @param[in] tlon The destination longitude.
 * @param[in] tlat The destination latitude.
 * @param[in] route_cb The route to be traced.
 * @param[in] data A pointer of user data.
 *
 * @return The created route or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Route * elm_obj_map_route_add(Elm_Map_Route_Type type, Elm_Map_Route_Method method, double flon, double flat, double tlon, double tlat, Elm_Map_Route_Cb route_cb, void *data);

/**
 * @brief Add a track on the map.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] emap The emap route object.
 *
 * @return The route object. This is an elm object of type Route.
 *
 * @ingroup Elm_Map
 */
EOAPI Evas_Object * elm_obj_map_track_add(void *emap);

/**
 * @brief Convert geographic coordinates (longitude, latitude) into canvas
 * coordinates.
 *
 * This gets canvas x, y coordinates from longitude and latitude. The canvas
 * coordinates mean x, y coordinate from current viewport.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lat The latitude to convert.
 * @param[out] x A pointer to horizontal coordinate.
 * @param[out] y A pointer to vertical coordinate.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_region_to_canvas_convert(double lon, double lat, Evas_Coord *x, Evas_Coord *y);

/**
 * @brief Add a new circle overlay to the map object. This overlay has a circle
 * type.
 *
 * Overlay created with this method can be deleted with @ref
 * elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lat The center latitude.
 * @param[in] radius The pixel length of radius.
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_circle_add(double lon, double lat, double radius);

/**
 * @brief Add a new class overlay to the map object. This overlay has a class
 * type.
 *
 * This overlay is not shown before overlay members are appended. if overlay
 * members in the same class are close, group overlays are created. If they are
 * far away, group overlays are hidden. When group overlays are shown, they
 * have default style layouts at first.
 *
 * You can change the state (hidden, paused, etc.) or set the content or icon
 * of the group overlays by chaning the state of the class overlay. Do not
 * modify the group overlay itself.
 *
 * Also these changes have a influence on the overlays in the same class even
 * if each overlay is alone and is not grouped.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_class_add(void);

/**
 * @brief Add a new bubble overlay to the map object. This overlay has a bubble
 * type.
 *
 * A bubble will not be displayed before geographic coordinates are set or any
 * other overlays are followed.
 *
 * This overlay has a bubble style layout and icon or content can not be set.
 *
 * Overlay created with this method can be deleted with @ref
 * elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_bubble_add(void);

/**
 * @brief Get the names of available sources for a specific type.
 *
 * It will provide a list with all available sources. Current source can be set
 * by @ref elm_obj_map_source_set, or get with @ref elm_obj_map_source_get.
 *
 * At least available sources of tile type are "Mapnik", "Osmarender",
 * "CycleMap" and "Maplint".
 *
 * At least available sources of route type are "Yours".
 *
 * At least available sources of name type are "Nominatim".
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] type Source type.
 *
 * @return The char pointer array of source names.
 *
 * @ingroup Elm_Map
 */
EOAPI const char ** elm_obj_map_sources_get(Elm_Map_Source_Type type);

/**
 * @brief Add a new polygon overlay to the map object. This overlay has a
 * polygon type.
 *
 * At least 3 regions should be added to show the polygon overlay.
 *
 * Overlay created with this method can be deleted with @ref
 * elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_polygon_add(void);

/**
 * @brief Add a new line overlay to the map object. This overlay has a line
 * type.
 *
 * Overlay created with this method can be deleted with  @ref
 * elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] flat The start latitude.
 * @param[in] tlon The destination longitude.
 * @param[in] tlat The destination latitude.
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_line_add(double flon, double flat, double tlon, double tlat);

/**
 * @brief Show the given coordinates at the center of the map, immediately.
 *
 * This causes map to redraw its viewport's contents to the region containing
 * the given @c lat and @c lon, that will be moved to the center of the map.
 *
 * See @ref elm_obj_map_region_bring_in for a function to move with animation.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lat Latitude to center at.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_region_show(double lon, double lat);

/**
 * @brief Request a address or geographic coordinates(longitude, latitude) from
 * a given address or geographic coordinate(longitude, latitude).
 *
 * If you want to get address from geographic coordinates, set input @c address
 * as @c null and set @c lon, @c lat as you want to convert. If address is set
 * except NULL, @c lon and @c lat are checked.
 *
 * To get the string for this address, @ref elm_map_name_address_get should be
 * used after callback or "name,loaded" signal is called.
 *
 * To get the longitude and latitude, @ref elm_map_region_get should be used.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lon The longitude.
 * @param[in] lat The latitude.
 * @param[in] name_cb The callback function.
 * @param[in] data The user callback data.
 *
 * @return A #Elm_Map_Name handle for this coordinate.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Name * elm_obj_map_name_add(const char *address, double lon, double lat, Elm_Map_Name_Cb name_cb, void *data);

/**
 * @brief Requests a list of addresses corresponding to a given name.
 *
 * @internal
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] name_cb The callback function.
 * @param[in] data The user callback data.
 *
 * @since 1.8
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_name_search(const char *address, Elm_Map_Name_List_Cb name_cb, void *data);

/**
 * @brief Animatedly bring in given coordinates to the center of the map.
 *
 * This causes map to jump to the given @c lat and @c lon coordinates and show
 * it (by scrolling) in the center of the viewport, if it is not already
 * centered. This will use animation to do so and take a period of time to
 * complete.
 *
 * See @ref elm_obj_map_region_show for a function to avoid animation.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lat Latitude to center at.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_region_bring_in(double lon, double lat);

/**
 * @brief Animatedly set the zoom level of the map and bring in given
 * coordinates to the center of the map.
 *
 * This causes map to zoom into specific zoom level and also move to the given
 * @c lat and @c lon coordinates and show it (by scrolling) in the center of
 * the viewport concurrently.
 *
 * See also @ref elm_obj_map_region_bring_in.
 *
 * @if MOBILE @since_tizen 3.0 @elseif WEARABLE @since_tizen 3.0 @endif
 *
 * @param[in] lon Longitude to center at.
 * @param[in] lat Latitude to center at.
 *
 * @since 1.11
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_region_zoom_bring_in(int zoom, double lon, double lat);

/**
 * @brief Remove a track from the map.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] route The track to remove.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_track_remove(Evas_Object *route);

/**
 * @brief Add a new route overlay to the map object. This overlay has a route
 * type.
 *
 * This overlay has a route style layout and icon or content can not be set.
 *
 * The color scheme can be changed by @ref elm_map_overlay_content_set.
 *
 * Overlay created with this method can be deleted with @ref
 * elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] route The route object to make a overlay.
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_route_add(const Elm_Map_Route *route);

/**
 * @brief Add a new scale overlay to the map object. This overlay has a scale
 * type.
 *
 * The scale overlay shows the ratio of a distance on the map to the
 * corresponding distance.
 *
 * Overlay created with this method can be deleted with @ref
 * elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y vertical pixel coordinate.
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_scale_add(Evas_Coord x, Evas_Coord y);

/**
 * @brief Add a new overlay to the map object. This overlay has a default type.
 *
 * A overlay will be created and shown in a specific point of the map, defined
 * by @c lon and @c lat.
 *
 * The created overlay has a default style layout before content or icon is
 * set. If content or icon is set, those are displayed instead of default style
 * layout.
 *
 * You can set by using @ref elm_map_overlay_content_set or @ref
 * elm_map_overlay_icon_set. If @c null is set, default style is shown again.
 *
 * Overlay created with this method can be deleted by @ref elm_map_overlay_del.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] lat The latitude of the overlay.
 *
 * @return The created overlay or @c null upon failure.
 *
 * @ingroup Elm_Map
 */
EOAPI Elm_Map_Overlay * elm_obj_map_overlay_add(double lon, double lat);

/**
 * @brief Convert canvas coordinates into geographic coordinates (longitude,
 * latitude).
 *
 * This gets longitude and latitude from canvas x, y coordinates. The canvas
 * coordinates mean x, y coordinate from current viewport.
 *
 * @if MOBILE @since_tizen 2.3 @elseif WEARABLE @since_tizen 2.3.1 @endif
 *
 * @param[in] y Vertical coordinate of the point to convert.
 * @param[out] lon A pointer to the longitude.
 * @param[out] lat A pointer to the latitude.
 *
 * @ingroup Elm_Map
 */
EOAPI void  elm_obj_map_canvas_to_region_convert(Evas_Coord x, Evas_Coord y, double *lon, double *lat);

EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_PRESS;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_ZOOM_CHANGE;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_TILE_LOAD;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_TILE_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_TILE_LOADED_FAIL;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_ROUTE_LOAD;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_ROUTE_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_ROUTE_LOADED_FAIL;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_NAME_LOAD;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_NAME_LOADED;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_NAME_LOADED_FAIL;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_OVERLAY_CLICKED;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_OVERLAY_DEL;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_LANGUAGE_CHANGED;
EOAPI extern const Eo_Event_Description _ELM_MAP_EVENT_ACCESS_CHANGED;

/**
 * No description
 */
#define ELM_MAP_EVENT_PRESS (&(_ELM_MAP_EVENT_PRESS))

/**
 * No description
 */
#define ELM_MAP_EVENT_ZOOM_CHANGE (&(_ELM_MAP_EVENT_ZOOM_CHANGE))

/**
 * No description
 */
#define ELM_MAP_EVENT_LOADED (&(_ELM_MAP_EVENT_LOADED))

/**
 * No description
 */
#define ELM_MAP_EVENT_TILE_LOAD (&(_ELM_MAP_EVENT_TILE_LOAD))

/**
 * No description
 */
#define ELM_MAP_EVENT_TILE_LOADED (&(_ELM_MAP_EVENT_TILE_LOADED))

/**
 * No description
 */
#define ELM_MAP_EVENT_TILE_LOADED_FAIL (&(_ELM_MAP_EVENT_TILE_LOADED_FAIL))

/**
 * No description
 */
#define ELM_MAP_EVENT_ROUTE_LOAD (&(_ELM_MAP_EVENT_ROUTE_LOAD))

/**
 * No description
 */
#define ELM_MAP_EVENT_ROUTE_LOADED (&(_ELM_MAP_EVENT_ROUTE_LOADED))

/**
 * No description
 */
#define ELM_MAP_EVENT_ROUTE_LOADED_FAIL (&(_ELM_MAP_EVENT_ROUTE_LOADED_FAIL))

/**
 * No description
 */
#define ELM_MAP_EVENT_NAME_LOAD (&(_ELM_MAP_EVENT_NAME_LOAD))

/**
 * No description
 */
#define ELM_MAP_EVENT_NAME_LOADED (&(_ELM_MAP_EVENT_NAME_LOADED))

/**
 * No description
 */
#define ELM_MAP_EVENT_NAME_LOADED_FAIL (&(_ELM_MAP_EVENT_NAME_LOADED_FAIL))

/**
 * No description
 */
#define ELM_MAP_EVENT_OVERLAY_CLICKED (&(_ELM_MAP_EVENT_OVERLAY_CLICKED))

/**
 * No description
 */
#define ELM_MAP_EVENT_OVERLAY_DEL (&(_ELM_MAP_EVENT_OVERLAY_DEL))

/**
 * No description
 */
#define ELM_MAP_EVENT_LANGUAGE_CHANGED (&(_ELM_MAP_EVENT_LANGUAGE_CHANGED))

/**
 * No description
 */
#define ELM_MAP_EVENT_ACCESS_CHANGED (&(_ELM_MAP_EVENT_ACCESS_CHANGED))

#endif
