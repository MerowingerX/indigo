
set (indigo_ccd_svb_src
  ${CMAKE_CURRENT_SOURCE_DIR}/indigo_ccd_svb_main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/indigo_ccd_svb.c
) 
 

add_executable(indigo_ccd_svb_bin ${indigo_ccd_svb_src})
add_library(indigo_ccd_svb_lib ${indigo_ccd_svb_src})

target_include_directories(indigo_ccd_svb_bin PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/bin_externals/libsvbcamera/include
)

target_include_directories(indigo_ccd_svb_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/bin_externals/libsvbcamera/include
)