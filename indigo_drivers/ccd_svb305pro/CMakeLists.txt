
set (indigo_ccd_svb305pro_src
  ${CMAKE_CURRENT_SOURCE_DIR}/indigo_ccd_svb305pro_main.c
  ${CMAKE_CURRENT_SOURCE_DIR}/indigo_ccd_svb305pro.c
) 
 

#add_executable(indigo_ccd_svb305pro_bin ${indigo_ccd_svb305pro_src})
add_library(indigo_ccd_svb305pro_lib ${indigo_ccd_svb305pro_src})

#target_include_directories(indigo_ccd_svb305pro_bin PUBLIC
#  ${CMAKE_CURRENT_SOURCE_DIR}/bin_externals/libsvbcamera/include
#)

target_include_directories(indigo_ccd_svb305pro_lib PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/bin_externals/libsvbcamera/include
)