message("preparing the indigo_server build")
message("project dir: " + ${PROJECT_SOURCE_DIR})
message("source dir: " + ${CMAKE_SOURCE_DIR})
message("current source dir: " + ${CMAKE_CURRENT_SOURCE_DIR})
set (IndigoServerFiles
    ${CMAKE_CURRENT_SOURCE_DIR}/indigo_server.c
 )

set (IndigoLibraryFiles
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_agent.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_align.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_ao_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_aux_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_avi.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_base64.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_bus.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_cat_data.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_ccd_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_client.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_client_xml.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_dome_azimuth.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_dome_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_driver_json.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_driver_xml.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_filter.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_fits.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_focuser_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_gps_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_guider_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_io.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_json.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_mount_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_novas.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_platesolver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_raw_utils.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_rotator_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_ser.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_server_tcp.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_tiff.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_timer.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_token.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_usb_utils.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_version.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_wheel_driver.c
 ${CMAKE_SOURCE_DIR}/indigo_libs/indigo_xml.c
) 
 
 # add the executable
add_executable(IndigoServer 
    ${IndigoServerFiles}
    ${IndigoLibraryFiles}
    )

#set the include directories
target_include_directories(IndigoServer PUBLIC 
    ${PROJECT_SOURCE_DIR}/indigo_server
    ${PROJECT_SOURCE_DIR}/indigo_drivers
    ${PROJECT_SOURCE_DIR}/indigo_libs
    ${PROJECT_SOURCE_DIR}/indigo_libs/externals/novas
    #${PROJECT_SOURCE_DIR}/indigo_libs/externals/libjpeg
    ${PROJECT_SOURCE_DIR}/indigo_libs/externals/hidapi
    #${PROJECT_SOURCE_DIR}/indigo_libs/externals/libtiff
    #${PROJECT_SOURCE_DIR}/indigo_libs/externals/libusb
    ${PROJECT_SOURCE_DIR}/indigo_linux_drivers
    )

function (cat_and_zip datafile)
  set(datafile_data ${datafile}_data )
  add_custom_target (
    ${datafile_data} ALL 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/constellations.bounds.json | gzip | hexdump -v -e '1/1 \"0x%02x, \"' > ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/constellations.bounds.json.data
    )  
endfunction()


add_custom_target(controldatafiles ALL
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/constellations.bounds.json | gzip | hexdump -v -e '1/1 \"0x%02x, \"' > ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/constellations.bounds.json.data
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/constellations.json | gzip | hexdump -v -e '1/1 \"0x%02x, \"' > ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/constellations.json.data
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/mw.json | gzip | hexdump -v -e '1/1 \"0x%02x, \"' > ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/mw.json.data
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/mng.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"' > ${CMAKE_CURRENT_SOURCE_DIR}/resource/mng.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/planets.json | gzip | hexdump -v -e '1/1 \"0x%02x, \"'   >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/data/planets.json.data
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/celestial.min.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'    >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/celestial.min.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/d3.min.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'           >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/d3.min.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/celestial.css | gzip | hexdump -v -e '1/1 \"0x%02x, \"'       >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/celestial.css.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/mng.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"'            >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/mng.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/ctrl.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"'           >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/ctrl.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/imager.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"'         >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/imager.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/mount.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"'          >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/mount.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/guider.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"'         >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/guider.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/script.html | gzip | hexdump -v -e '1/1 \"0x%02x, \"'         >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/script.html.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/indigo.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'           >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/indigo.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/mng.png | gzip | hexdump -v -e '1/1 \"0x%02x, \"'             >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/mng.png.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/components.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'       >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/components.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/mount.png | gzip | hexdump -v -e '1/1 \"0x%02x, \"'           >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/mount.png.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/ctrl.png | gzip | hexdump -v -e '1/1 \"0x%02x, \"'            >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/ctrl.png.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/imager.png | gzip | hexdump -v -e '1/1 \"0x%02x, \"'          >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/imager.png.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/guider.png | gzip | hexdump -v -e '1/1 \"0x%02x, \"'          >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/guider.png.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/script.png | gzip | hexdump -v -e '1/1 \"0x%02x, \"'          >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/script.png.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/indigo.css | gzip | hexdump -v -e '1/1 \"0x%02x, \"'          >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/indigo.css.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/bootstrap.min.css | gzip | hexdump -v -e '1/1 \"0x%02x, \"'   >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/bootstrap.min.css.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/glyphicons.css | gzip | hexdump -v -e '1/1 \"0x%02x, \"'      >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/glyphicons.css.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/jquery.min.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'       >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/jquery.min.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/bootstrap.min.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'    >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/bootstrap.min.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/popper.min.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'       >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/popper.min.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/vue.min.js | gzip | hexdump -v -e '1/1 \"0x%02x, \"'          >  ${CMAKE_CURRENT_SOURCE_DIR}/resource/vue.min.js.data 
    COMMAND cat ${CMAKE_CURRENT_SOURCE_DIR}/resource/glyphicons-regular.ttf | gzip | hexdump -v -e '1/1 \"0x%02x, \"' > ${CMAKE_CURRENT_SOURCE_DIR}/resource/glyphicons-regular.ttf.data    
)

add_custom_target(
    ctrlpaneldata 
    DEPENDS ${controldatafiles}
   

   
)

add_dependencies(IndigoServer ctrlpaneldata)