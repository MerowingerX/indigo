# Changelog

All notable changes to INDIGO framework will be documented in this file.

## [2.0-170] - 05 Mar Sat 2022
### Overall
- indigo_platesolver: do not fail the whole process if platesolve during recalculate fails
- indigo_platesolver: implement refraction compensation for polar alignment
- indigo_platesolver: start_exposure() checks for available camera
- indigo_platesolver: better error handling
- indigo_platesolver: start_exposure() checks if the camera is available
- indigo_platesolver: better AGENT_PLATESOLVER_PA_STATE property state transitions
- Makefile: libhidapi-libhidraw.a replaced with libhidapi-libusb.a

### Driver fixes
- indigo_astrometry_agent:
	- see overall: indigo_platesolver

- indigo_astap_agent:
	- see overall: indigo_platesolver

- indigo_ccd_atik:
	- EFW1/2 SDK support added to the CCD driver

- indigo_wheel_atik:
	- usb rules fixed

- indigo_ccd_simulator:
	- set more reasonable value for default image in Guider Camera

- indigo_ccd_svb:
	- initialization fixed
	- workatound for prematurely ended exposures

## [2.0-168] - Mon Feb 21 2022
### Overall
- added WRITE_ONLY BLOBs
- indigo_platesolver: added 3 point polar alignment
- indigo_platesolver: local files can be uploaded for solving
- indigo_platesolver: code refactored
- indigo_platesolver: add processes
- indigo_prop_tool: add support for WRITE_ONLY BLOBs
- indigo_libs: libnovas fixed for arm64 linux machines
- indigo_libs: HIDAPI switched from libraw to libusb on linux
- indigo_docs: POLAR_ALIGNMENT.md added
- ccd_driver: byte_order_rgb interpreted correctly for TIFF format

### New drivers
- indigo_astap_agent:
	- plate solver agent using ASTAP
	- has all the features as Astrometry agent

- indigo_ccd_svb:
	- driver for SvBony cameras

### Driver fixes
- indigo_astrometry_agent:
	- solving can be triggered by a processes
	- added 3-point polar alignment
	- local files can be uploaded for solving
	- solution can be transformed to JNow
	- fix abort function
	- fixed cleanup of the temporary files

- indigo_agent_imager:
	- dithering can skip frames

- indigo_agent_scripting:
	- race fixed

- indigo_ccd_simulator:
	- Hipparcos data is used for real sky images from "CCD Guider Simulator"
	- add polar error simulation
	- images from "CCD Guider Simulator" can be in JNow or J2000
	- "CCD Guider Simulator" frame size is user defined

- indigo_ccd_asi:
	- use SDK v1.21
	- fix array overrun
	- number.target vs. number.value cleanup

- indigo_gps_nmea:
	- support for Glonass messages

- indigo_ccd_qhy:
	- provde hack for missing pthread_yield() call

- indigo_mount_synscan:
	- add support for "StarSeek" mounts

- indigo_ccd_ptp:
	- Fuji driver improved, tested with XT1
	- add Canon EOS 250D
	- add Fujifilm X-S10
	- generalised image download code for Fujifilm
	- Sony A7R4 compatibility fixes

- indigo_mount_lx200:
	- add experimental support for ZWO AM5 mount
	- 10micron bugfixes
	- guiding commands made synchronous
	- mount type override fixed

- indigo_mount_ioptron:
	- guiding commands made synchronous

- indigo_mount_pmc8:
	- new firmware support added
	- rounding issues fixed

- indigo_focuser_fcusb:
	- rules file added

## [2.0-166] - Tue Nov 30 2021
### Overall
- indigo_raw_utils: new API for RMS contrast estimator
- IMAGING_AF_TUNING: updated to reflect the latest AF changes
- indigo_process_image(): fix sending of a wrong error message

### Driver fixes
- indigo_agent_imager:
	- complete rewrite of RMS contrast estimator
	- RMS AF supports RGB images
	- RMS AF is not confused by saturated areas any more

- indigo_ccd_touptek:
	- SDK updated to 50.19728.20211022

- indigo_ccd_atik:
	- SDK updated to SDK_2021_11_02

- indigo_ccd_asi:
	- SDK updated to 1.20.3

- indigo_ccd_qhy2:
	- SDK updated to V2021.10.12 (x86 driver uses the old version - QHY dropped 32bit Linux support)

- indigo_ccd_qhy/indigo_ccd_qhy2:
	- camera firmware update

- indigo_ccd_uvc:
	- image buffer overrun fixed

- indigo_ccd_mi:
	- Update ibgxccd for MacOS to version 0.5.1 (fixes issue with Monterey when camera did not connect the first time after power on)

- indigo_mount_simulator:
	- fix MOUNT_TRACKING property state transitions

## [2.0-164] - Fri Nov 05 2021
### Overall
- indigo_dtos(): call fixed formatting issues
- indigo_stod(): fix for values [-1, 0] represented as positive
- libusb: updated

### Driver fixes
- indigo_agent_solver:
	- more reliable "Sync and center"
	- FOV unit parsing fixed

- indigo_agent_imager:
	- Peak/HFD focus failed criteria fixed
	- BEST_FOCUS_DEVIATION item added as a measure of the deviation of the final focus quality compared to the best of the run
	- return to initial on failure fixed
	- fix memory leak in capture_raw_frame()
	- prevent abort_process() from aborting all devices on the bus when no focuser selected
	- do not evaluate RMS contrast on frame restoration as contrast changes dramatically when frame is changed

- indigo_agent_guider:
	- fixed calibration near the poles

- indigo_ccd_ptp:
	- Fuji camera BULB exposure fixed
	- Fuji X-T2 support

- indigo_focuser_mypro2:
	- fix proeprty handling

- indigo_mount_lx200:
	- OnStep compatibility issue fixed

- indigo_mount_ioptron:
	- search for mechanical zero position added for CEM45, CEM70 and CEM120
	- MOUNT_PARK_SET implemented for 2.5 and 3.0 protocols

- indigo_ccd_asi:
	- lower the camera stress at exposure start
	- fix ASI120 issues
	- SDK updated v.1.20.2.1103

- indigo_ccd_simulator:
	- backlash simulation added
	- add declination to the drift to simulate high declination guiding
	- change GUIDER_IMAGE to SIMULATION_SETUP property

- indigo_ccd_uvc:
	- libuvc updated

## [2.0-162] - Fri Oct 15 2021
### Overall
- indigo_filter: device and related device validation callback added
- indigo_docs: updated IMAGING_AF_TUNING.md
- indigo_framework: add indigo_contrast() call to calculate Root Mean Square (RMS) contrast of the image

### Driver fixes
- indigo_agent_imager:
	- add new backlash clearing strategy "Backlash overshoot"
	- add new autofocus estimator "RMS contrast"
	- remove FWHM from original focus quality estimator - tests show it does not work well.
	- user can select autofocus estimator: "Peak/HFD" or "RMS contrast"
	- sequencer doesn't fail if autofocus fails, autofocus restores initial position if it fails
	- AGENT_IMAGER_FOCUS_FAILURE property added with the option to return to starting position (Peak/HFD estimator only)
	- add possibility to retry focus on failure (user configurable)
	- focusing statistics are cleared on focus start
	- better autofocus error handling
	- manual focusing fixed
	- fix ABORT_PROCESS ending in endless loop with message 'Failed to evaluate quality'
	- the error 'FOCUSER_STEPS_PROPERTY didn't become OK' is not shown if process is aborted or no move us performed.
	- external shutter support added
	- Changed AF max move limits to:
		- 20 * Initial step for Peak/HFD estimator
		- 40 * Initial step for RMS contrast estimator

- indigo_aux_flipflat:
	- command delimiters fixed
	- fix default linux serial port name

- indigo_aux_joystick:
	- macOS deadlocks fixed

- indigo_ccd_ptp:
	- fix A7R4 capture issues
	- external shutter support added for Nikon

- indigo_mount_ioptron:
	- some more protocol 3.1 firmware versions added
	- more Fuji models added

## [2.0-160] - Wed Sep 15 2021
### Driver fixes
- indigo_ccd_asi:
	- updated SDK to 1.20
		- adds support for ASI482 and ASI485
		- fixes the problem that ASI2600 sometimes fails to obtain data
		- fixes the problem of image tearing after ASI2600 switching resolution
		- the ASI183 ROI function is rolled back to obtain a higher frame rate
		- fixes an occasional failures to open the camera

- indigo_ccd_atik:
	- update SDK to SDK_2021_09_06

## [2.0-158] - Sun Aug 29 2021
### Overall:
- indigo_raw_to_fits(): user provideds keyword can be added
- indigo_raw_to_fits: the tool can add BAYERPAT, CCD-TEMP and EXPTIME keywords
- TIFF/JPEG buffer size fixed
- dome drivers: DOME_DIMENSION property made persistent
- indigo docs: IMAGING_AF_TUNING - guidelines for auto focus tuning

### New Drivers
- indigo_aux_geoptikflat: Geoptik flat field generator driver

### Driver fixes
- indigo_agent_imager:
	- fix backlash application if it is handled by the driver
	- fix CCD_UPLOAD_MODE_PROPERTY and CCD_IMAGE_FORMAT_PROPERTY restoration in preview process

- indigo_agent_guider:
	- multi-star guiding now works with less than required stars
	- change some messages

- indigo_agent_mount: AGENT_SET_HOST_TIME_PROPERTY made persistent

- indigo_ccd_atik:
	- window heater support added

- indigo_ccd_asi:
	- RREADME.md updated

## [2.0-156] - Sun Jul 26 2021
### Overall:
- j2k coordinates added to indigo_topo_planet()

### Driver fixes
- indigo_agent_astrometry: index download or solving can be aborted

- indigo_agent_guider:
	- settling limit made configurable (AGENT_GUIDER_SETTINGS_DITH_LIMIT_ITEM)
	- dec-only calibration fixed
	- guiding will fail if RA speed = 0

- indigo_ccd_mi:
	- driver made multiplatform on macOS
	- add support for Moravian C1×, C3 and C4 cameras

- indigo_ccd_asi:
	- update sdk to 1.19.2

## [2.0-154] - Sat Jul 03 2021
### Overall:
- indigo_server: by default blob compression is disabled

- indigo_framework:
	- add indigo_azimuth_distance() and used in dome drivers
	- define new PWM related properties

- indigo_solver: fix Sync & Center for some mounts with lazy sync operation

- indigo_prop_tool:
	- accept timeout 0
	- timeout countdown is started only if the connection is established

### New Drivers
- indigo_dome_beaver: Driver for NexDome domes with beaver controllers

- indigo_aux_astromechanics: ASTROMECHANICS Light Pollution Meter driver - untested

- indigo_focuser_astromechanics:  ASTROMECHANICS focuser driver - untested

### Driver fixes
- indigo_ccd_asi:
	- updated to SDK v.1.19.1 - fixes multi camera issue
	- fix unity gain calculation for cameras with full well < ADC resolution
	- show firmware version in the device info property

- indigo_focuser_asi:
	- updated to SDK v.1.4 - fixes 5v EAF crashes.

- indigo_whell_asi:
	- updated to SDK v.1.7
	- show firmware version in the device info property

- indigo_aux_rpio: add PWM support (see driver README.md)

## [2.0-152] - Sun Jun 13 2021
### Overall:
- indigo_client: fix http timeout for blob transfer - RPi is slow at compressing large images
- fix typo leading to server self lock.

### Driver fixes
- indigo_ccd_altair: macOS library architecture fixed

## [2.0-150] - Wed Jun 09 2021
### Overall:
- do not exit on libjpeg errors
- libjpeg error handling race fixed
- added indigo_raw_to_fits() call
- new tool added "indigo_raw_to_fits"
- indigo_platesolver: add step to some items and use degree sign in the labels
- MOUNT_EPOCH uses J2000 istead of JNOW
- added full NGC/IC catalog
- fix random behavior while removing related agent

### Driver Fixes
- indigo_aux_ppb: PPB Micro support added
- indigo_ccd_simulator: battery level property added

- indigo_ccd_asi:
	- revert SDK to v.1.16.3 for arm (because of regressions)
	- update SDK to v.1.18 for Intel Linux and macOS
	- default bandwidth set to 45 to allow 2 cameras to work at the same time

- indigo_agent_astrometry:
	- FOV property added
	- index download synchronized
	- index sizes shown in labels
	- fix missing sync before center
	- pix potential race
	- better error handling
	- make AGENT_PLATESOLVER_WCS property busy while mount is slewing
	- update AGENT_PLATESOLVER_WCS when ready but remain busy while slewing
	- pixel scale fixed

- indigo_ccd_ptp:
	- Nikon Z6II support
	- Nikon Z7II support
	- Canon M50mk2 support
	- ExposureDelayMode fixed for D780
	- NULL pointer exception handled

## [2.0-148] - Thu Apr 29 2021
### Overall:
- better memory management - allocated buffers reuse
- fixed some memory leaks
- fixed telescope alignment
- wifi channel can be selected for indigo sky in Access Point mode

### Driver Fixes
- indigo_mount_ioptron: add firmware version 3.1
- indigo_wheel_qhy: fix typo

## [2.0-146] - Wed Apr 14 2021
### Overall:
- compression added to HTTP BLOB transfer - image transfer can be about 2x faster
- introduce DOME_HOME and DOME_PARK_POSITION properties
- prepare the build for arm64 version of INDIGOSky
- platesolver agents: dec limit fixed
- fix indigo_dtos() showing negative degrees < 1 as positive
- HTTP server: dynamic content handling support added
- indigo_driver: save port and baud rate at property change
- additional serial ports removed from macOS list
- select() timeout fixed
- fixed memory leaks in mount base class
- DSLR JPEG->RAW conversion issue fixed
- debug log level setting fixed
- add indigo_compensate_backlash() call to be used in rotators and focusers

### New Drivers:
- indigo_agent_alpaca: Agent that exposes INDIGO devices to ASCOM/Alpaca clients.
- dome_talon6ror: driver for Talon 6 dome controller

### Driver Fixes:
- indigo_agent_imager:
	- focuser backlash and agent backlash properties synchronized

- indigo_agent_mount:
	- geographic coordinates propagation is limited by this threshold
	- synchronization fixed

- indigo_agent_astrometry:
	- index names made consistent
	- index management fixed
	- remote mount agent snooping fixed
	- solved message added

- indigo_guider_agent:
	- rename Integral stacking -> Integral stack size; docs updted

- indigo_mount_ioptron:
	- firmware 210105 detection added
	- driver refactoring
	- synchronization issues fixed
	- MSH used instead of MH for protocol 3.0
	- search for mechanical zero item added for 2.5 and 3.0 protocols

- indigo_mount_nexstar:
	- fix the busy state of the coordinate properties
	- fix equatorial tracking start / stop
	- fix tracking mode being stopped on connect

- insigo_ccd_altair:
	- SDK updated

- indigo_focuser_efa:
	- stack overrun fixed

- indigo_focuser_asi:
	- STEPS and POSITION states synchronized
	- SDK updated

- indigo_ccd_asi:
	- SDK updated

- indigo_wheel_asi:
	- SDK updated

- indigo_ccd_qhy:
	- firmware updated
	- READ_MODE change resets CCD_INFO, CCD_FRAME and CCD_MODE now
	- resolution fixed

- indigo_ccd_qhy2:
	- SDK and firmware updated
	- READ_MODE change resets CCD_INFO, CCD_FRAME and CCD_MODE now
	- resolution fixed

- indigo_wheel_qhy:
	- fix move Busy state

- indigo_focuser_dsd:
	- STEPS and POSITION states synchronized
	- software backlash compensation implemented

- indigo_focuser_fli:
	- STEPS and POSITION states synchronized

- indigo_focuser_lunatico:
	- STEPS and POSITION states synchronized

- indigo_focuser_mypro2:
	- STEPS and POSITION states synchronized
	- software backlash compensation implemented
	- load settings fixed

- indigo_dome_baader:
	- synchronized steps and horizontal coordinates states
	- fixed stale busy state in some situations

- indigo_dome_nexdome:
	- abort handled gracefully
	- fixed stale busy state in some situations

- indigo_dome_nexdome3:
	- abort handled gracefully
	- fixed property states

- indigo_aux_rpio:
	- replace GPIO 19 with GPIO 21
	- replace GPIO 04 with GPIO 19

- indigo_aux_upb:
	- outlet name items order fixed

- indigo_aux_ppb:
	- outlet names property name fixed

- indigo_ccd_simulator:
	- focuser absolute position setting enabled

- indigo_dome_simulator:
	- made shutter open and close timely operation

- indigo_wheel_quantum:
	- refactoring

- indigo_wheel_xagyl:
	- filter count fixed

- indigo_dome_skyroof:
	- fix abort state

- indigo_ccd_sbig:
	- driver now available for arm64 linux

## [2.0-144] - Sun Feb 28 2021
### Overall:
- add conditional deb dependency to indigo-astrometry or astrometry.net
- indigo_client: fix race condition
- weather & sky conditions properties standardized
- indigo_docs: GUIDING_PI_CONTROLLER_TUNING added

### New Drivers:
- indigo_dome_skyroof: Interactive Astronomy SkyRoof driver added
- insigo_aux_skyalert: Interactive Astronomy SkyAlert driver added

### Driver Fixes:
- indigo_agent_imager:
	- DSLR raw formats added to download code

- indigo_agent_guider:
	- multi-star selection mode added
	- donuts will repeat 3x in case of poor SNR
	- fix buffer size in indigo_find_stars_precise()
	- make drift detection more precise
	- new Proportional-Integral controller implementation, Proportional Weight is removed in favor of Integral gain

- indigo_agent_mount:
	- disconnect bug fixed
	- lx200 server cleanup

- indigo_mount_ioptron:
	- GEM45EC support added
	- MOUNT_CUSTOM_TRACKING_RATE support implemented
	- lunar tracking rate fixed
	- hc8407 support added
	- GEM45 support added

- indigo_mount_rainbow:
	- SYNC fixed
	- detach fixed

- indigo_ccd_asi:
	- BPP can be set from CCD_FRAME

- indigo_ccd_qsi:
	- fix CCD_TEMPERATURE handling

- indigo_ccd_touptek:
	- fix CCD_TEMPERATURE handling

- indigo_ccd_altair:
	- fix CCD_TEMPERATURE handling

- indigo_mount_lx200:
	- simulator fixed
	- aGotino support added

- indigo_ccd_simulator:
	- cooler control is consistent with real ccd drivers now

- indigo_dome_simulator:
	- state fixes

## [2.0-142] - Sat Jan 23 2021
### Overall:
- indigo_server: BLOB proxy added for remote servers
- WebGUI: fixed to work with proxied BLOBs
- various documentation updates
- agents can not change selected device while they are in use
- agent INTERFACE item can now e used to identify what devices are controlled
- agents crashes on device unload fixed
- devices opened by agents are closed on agent detach
- better star detection algorithm
- more precise version of find stars added
- XML client/driver cleanup
- JSON BLOB definition carries URL now
- long TEXT property support fixes
- property cache access synchronization in XML client added
- large buffers moved from stack to heap
- JPEG to RAW conversion added to indigo_process_dslr_image()
- several races and crashes fixed in indigo client
- fix several small memory leaks
- fix agents crash when some properties are deleted
- device detach code fixes: no need to explicitly call disconnect at detach

### New Drivers:
- indigo_agent_astrometry: Agent for plate solving using astrometry.net (indigo-astrometry should be installed).

### Driver Fixes:
- indigo_agent_imager:
	- sub-framing support added to preview process
	- sub-frame selection fixes
	- BLOB content race fixed

- indigo_agent_guider:
	- subframe selection fixes
	- make Donuts guider resilient to hot columns and rows
	- make Selection guide resilient to hot columns and rows
	- Donuts guider optimized
	- Edge Clipping added to Donuts guider
	- BLOB content race fixed
	- some parts are refactored

- indigo_agent_mount: AGENT_SET_HOST_TIME added

- indigo_ccd_uvc:
	- libuvc updated
	- mono formats supported
	- exposure countdown fixed
	- bug fixes

- indigo_ccd_ptp:
	- automatic use of LiveView during focusing
	- DSLR_EXPOSURE_METERING_PROPERTY_NAME on Canon fixed
	- high precision bulb time measurement
	- RAW format support added
	- Nikon focusing fixed

- indigo_mount_rainbow:
	- communication with the mount while it is not connected is fixed
	- lat/long format fixed

- indigo_ccd_simulator:
	- fix mixed width and height
	- DSLR simulator RAW format support added

- indigo_ccd_asi: update SDK v.1.16.3
- indigo_agent_scripting: enhancements
- indigo_aux_rpio: change pins which overlap with the default i2c


## [2.0-140] - Sun Dec 27 2020
### New Drivers:
- indigo_mount_rainbow: RainbowAstro mount driver
- indigo_agent_scripting: ECMAscript support for INDIGO


## [2.0-138] - Sun Dec 27 2020
### License Change
- INDIGO Astronomy open-source license version 2.0: Changed the license to more permissive and more compatible one.

### Overall:
- Added ECMAscript support for INDIGO through indigo_agent_scripting.
- Text property can have unlimited length
- Web GUI has support for scripting
- indigo_prop_tool has support for scripting
- Offset and Gamma added to XISF metadata
- Some JSON escaping fixed
- Memory leaks fixed in XML and JSON parsers and  indigo_ccd_driver
- JPEG preview stretching fixed for 16 bit images
- CCD_JPEG_SETTINGS_PROPERTY doesn't show and hide
- Data can be passed to timers using indigo_set_timer_with_data()
- indigo_resize_property() call fixed

### Driver Fixes:
- indigo_agent_guider:
	- fix guiding issue when with Declination guiding off
	- calculate correctly RMSE RA and Dec
	- dithering RMSE is cleared
	- preview and guiding state transition fixed
	- fix dithering issue

- indigo_agent_alignment: interface code fixed
- indigo_agent_imager: do not fail batch if the dithering failed to settle
- indigo_focuser_asi: workaround for SDK issue related to device hotplug applied
- indigo_mount_ioptron: park bug fixed
- indigo_aux_dsusb: dual arch macOS libraries added
- indigo_focuser_fcusb: dual arch macOS libraries added
- indigo_guider_gpusb: dual arch macOS libraries added
- indigo_wheel_atik: dual arch macOS libraries added

## [2.0-136] - Sat Dec 5 2020
### Overall:
- Optional automatic subframing added to autofocus and guiding processes in imager and guider agent
- More robust automatic stretching for JPEG preview
- CCD File Simulator device added to CCD Simulator driver (provides an image from specified RAW file)
- RGBA and ABGR raw format support added to guider utility functions
- Large files support added to RPi builds
- Histogram added to webGUI of imager agent
- Optional double buffering support added in INDIGO server for BLOB requests
- DEVICE_DRIVER added to INFO property (issue #132)
- DARKFLAT added to CCD_IMAGE_FORMAT property (issue #387)
- indigo_property_match_w() added
- fixed read only property handling in core library

### Driver Fixes:
- indigo_mount_nexstar:
	- experimental guide pulse support added
	- several bugfixes

- indigo_ccd_qhy2:
	- SDK updated

- indigo_ccd_altair:
	- SDK updated

- indigo_ccd_ptp:
	- Support for Canon EOS R5 and R6 cameras

- indigo_focuser_lunatico:
	- temperature compensation fixed

- indigo_focuser_dsd:
	- temperature compensation fixed

- indigo_focuser_asi:
	- temperature compensation fixed

### New Drivers:
- indigo_focuser_mypro2

## [2.0-134] - Mon Nov 16 2020
### Overall:
- Fix IndigoSky regression


## [2.0-132] - Sat Nov 14 2020
### Overall:
- More robust socket handling
- More robust FWHM calculation
- Internet sharing option added to IndigoSky build
- BLOB caching synchronization fixes
- AVI support added to DSLR drivers

### Driver Fixes:
- indigo_aux_cloudwatcher:
	- support for Pocket CW
	- support for older AAG units
	- bug fixes

- indigo_agent_guider: add steps to AGENT_GUIDER_SETTINGS

- indigo_ccd_ptp:
 	- Support for Fujifilm cameras
	- Sony camera fixes

- indigo_mount_pmc8: connection issues fixed
- indigo_mount_nexstar: StarSense related fixes
- indigo_ccd_qhy / indigo_ccd_qhy2: many driver and SDK fixes

### New Drivers:
- indigo_wheel_qhy: QHY standalone filter wheels driver
- indigo_mount_nexstaraux: Celestron Wifi mount drivers

### Obsoleted drivers
- indigo_ccd_gphoto2: removed from the build - indigo_ccd_ptp replaces it

## [2.0-130] - Sun Nov 01 2020
### Overall:
- TIFF image format added to CCD drivers
- AVI and SER format support added to streaming CCD drivers
- indigo_guider_utils: more robust HFD/FWHM calculation
- indigo_server_tcp: empty resource list bug fixed
- VERIFY_NOT_CONNECTED() macro fixed
- scientific number notation support added to JSON
- CLIENT_DEVELOPMENT_BASICS.md and INDIGO_AGENTS.md documents updated

### Driver Fixes:
- indigo_agent_imager:
  - report failure if focusing did not converge
  - more robust focusing
  - fix rare crash due to unitialized frame digest


- indigo_mount_nexstar:
  - set correct timezone and DST
  - GPS detection changed
  - deadlock fixed


- indigo_ccd_simulator:
  - focuser: more realistic out of focus images
  - bug fixes


- indigo_ccd_touptek: fix failing exposures problem
- indigo_ccd_altair: fix failing exposures problem
- indigo_mount_ioptron: CEM70 identification added
- indigo_focuser_usbv3: bug fixes


### New Drivers:
- wheel_qhy: QHY standalone filter wheel driver

## [2.0-128] - Mon Oct 05 2020
### Overall:
- Agents can select only devices that are not currently being used.
- Add star auto detection used for focusing and guiding via indigo_find_stars()
- Better HFD calculation with unlimited radius
- webGUI: auto focus, guiding mode and dithering added
- XISF metadata fixed and extended

### Driver Fixes:
- indigo_agent_guider:  many enhancements the main ones are:
  - Guiding now uses real Proportional-Integral (PI) controller. Explained in the driver README.md.
  - Dithering process auto detects when the guiding settled.
  - Selection guide: more robust, sensitive and stable implementation,
    a suitable star is auto selected if no selection is made,
    stars can be manually selected from a list too.
  - Donuts guide: more robust, sensitive and stable implementation
  - Centroid guide: more robust, sensitive and stable implementation
  - Code optimizations
  - Bug fixes


- indigo_agent_imager:
  - Auto select star for focusing process.
  - dithering with remote guider agent fixed
  - Bug fixes


- indigo_ccd_simulator:
  - simulate hotpixels and hot rows/columns
  - RA/DEC_OFFSET items added to GUIDER_SETTINGS to simulate random tracking errors
  - Bug fixes


- ccd_qhy/ccd_qhy2:
  - SDK & firmare updated
  - Remove hot-plug support - SDK does not really support this
  - increase buffer size for 60+ MPx cameras


- ccd_altair:
  - binning issues fixed
  - SDK updated to 48.17729.2020.0922


- ccd_touptek:
  - binning issues fixed
  - SDK updated to 46.17309.20200616


- indigo_ccd_asi: SDK updated to 1.15.0915
- indigo_ccd_ptp: bugfixes

## [2.0-126] - Wed Sep 01 2020
### Overal:
- alignment routines improved
- security token support fixed
- DLL build added to Windows makefile
- PSF calculation fixed

### Driver Fixes:
- indigo_ccd_atik: macOS Horizon issues fixed
- indigo_ccd_qsi: improved, fixed and tested with physical hardware
- indigo_mount_pmc8: protocol switching fixed
- indigo_ccd_ptp: Nikon Z5 support added
- indigo_ccd_simulator: streaming and BULB support added
- indigo_agent_mount: stops capture on related ccd agent on park etc.

## [2.0-124] - Sat Aug 01 2020
### Overal:
- Double connection issue fixed
- PSF computation fixed
- several executable drivers were not built
- indigo_server: better process handling
- added indigo_examples folder and created new examples
- Documentation update
- added user documentation about indigo_prop_tool and indigo_server
- fixed blob transfer for executable drivers
- blob transfer improvements - name resolution is done only once
- support ROWORDER keyword in fits.

### Driver Fixes:
- indigo_agent_guider: PSF radius added, fixes
- indigo_agent_imager: PSF radius added, fixes
- indigo_aux_ppb: PPB Advanced support added
- indigo_aux_sqm: crash fixed
- indigo_ccd_qsi: initial slot position fixed, added rules
- indigo_ccd_mi: SDK updated to 0.5.6
- indigo_ccd_asi: SDK updated to 1.15.0617
- indigo_wheel_asi: SDK updated to 1.5.0615
- indigo_focuser_asi: SDK updated to 0.2.0605
- indigo_mount_lx200: meridian flip control added to AvalonGO dialect
- indigo_ccd_atik: SDK updated to 2020_06_23
- indigo_ccd_qhy2: SDK updated to V2020.06.05 for macOS and  V2020.05.22 for linux

### New Drivers:
- indigo_mount_pmc8: PMC8 mount controller driver
- indigo_aux_rpio: Raspberry Pi GPIO driver

## [2.0-122] - Fri May 05 2020
### Overal:
- Device access control finished
- New more robust timer handling
- INDIGO_AGENT class added
- Dynamic libraries ARE NOT binary compatible due to changes in indigo_device structure
- Drivers can not be unloaded if any of the handled devices is connected

### Driver Fixes:
- ALL DRIVERS are updated due to the new timer handling
- indigo_efa_focuser: calibration added for celestron devices
- indigo_lx200_mount: unpark added for OneStep dialect, tracking status fixed, ...
- indigo_ioptron_mount: iEQ25 parking fixed, protocol 2.5+ guiding rate setting fixed, ...
- indigo_focuser_optec: relative move orientation fixed, reverse orientation property added
- indigo_focuser_dmfc: relative move response reading fixed
- indigo_aux_sqm: crash on lost connection fixed
- indigo_aux_rts: disconnect sequence fixed
- indigo_aux_ppb: dev heater initial target values fixed, P3/P4 fixed, ...
- indigo_aux_flipflat: light intensity reading fixed
- indigo_focuser_moonlite: timeout fixed
- indigo_ccd_ptp: D3000/3100 capture fixed
- indigo_ccd_atik: AtikOne wheel control fixed, new SDK used
- indigo_ccd_mi: support for new CMOS cameras added

### New Drivers:
- indigo_dome_baader
- indigo_aux_mgbox
- indigo_wheel_manual
- indigo_aux_cloudwatcher

## [2.0-120] - Sat Apr 04 2020
### Overall:
- New experimental feature: Add device access control
- indigo_server:
    - Fix deadlock on indigosky
    - Fix password trucation bug

### Driver Fixes:
- indigo_ccd_ptp: Sony camera related fixes
- indigo_mount_temma: Side of pier fixed

## [2.0-118] - Sun Mar 22 2020

### Overall:
- indigo framework: fix "&" character escape in XML

### Driver Fixes:
- indigo_ccd_ptp: Sony and Canon camera related fixes
- indigo_mount_temma: Add pier side update notify

### New Drivers:
- indigo_dome_dragonfly: Lunatico Astronomia Dragonfly Dome / Relay controller driver
- indigo_aux_dragonfly: Lunatico Astronomia Dragonfly Relay controller driver


## [2.0-116] - Mon Mar 9 2020

### Overall:
- indigosky fixes

### Driver fixes:
- lunatico drivers: show proper description

## [2.0-114] - Sat Mar 7 2020

### Overall:
- indigo_server: several fixes
- indigo_prop_tool: fix quotes management in set value
- indigo_framework:
    - added Rotator device support
    - added AUX GPIO (General puspose I/O device, to control relays, sensor
      arrays, switches etc.) device support
    - added several new utility functions
    - drivers can mutually exclude each other
    - usbfs_memory_mb fixed - no more failed frames with several camera connected
    - use updated version of fxload
- Developer Documentation updated

### Driver Fixes:
- indigo_mount_nexstar: fixes and worarounds for StarSense HC
- indigo_focuser_dsd: add support for DSD AF3
- indigo_agent_guider: abort fixed, remote driver fixed
- indigo_agent_imager: remote driver fixed, several enhancements
- indigo_ccd_ptp: Added support for several Sony, Canon and Nikon cameras, Sony
  and Nikon camera related fixes
- indigo_focuser_moonlite: timeout increased
- indigo_ccd_asi: firmware updated to v.1.14.1227
- indigo_ccd_qhy: camera firmware updated, but the QHY provided SDK is still badly unstable

### New Drivers:
- indigo_focuser_lunatico: Lunatico Astronomy Limpet/Armadillo/Platypus Focuser/Rotator/Powerbox/GPIO driver
- indigo_rotator_lunatico: Lunatico Astronomy Limpet/Armadillo/Platypus Rotator/Focuser/Powerbox/GPIO driver
- indigo_rotator_simulator: Rotator simulator deiver
- indigo_ccd_qhy2: The same as main qhy driver but uses different less stable sdk :( but hopefully it will support more cameras.

## [2.0-112] - Sun Jan 26 2020

### Overall:
- Developer documentation added

### Driver fixes:
- indigo_mount_temma: bug fixes
- infigo_ccd_atik: SDK updated
- indigo_focuser_dmfc, indigo_aux_upb: focuser speed limits fixed
- indigo_mount_lx200: AvalonGO support improved
- indigo_ccd_ptp: LiveView buffer race fixed


## [2.0-110] - Tue Jan 14 2020

### Overall:
- Add missing FITS keywords to xisf format
- fix FITS keyword DATE-OBS to indicate exposure start

### New Drivers:
- indigo_gps_gpsd: GPSD client driver

### Driver fixes:
- indigo_gps_nmea: bug fixes
- infigo_ccd_ptp:
    - Add Canon EOS 90D
    - Sony fixes
    - capture sequence standardized
    - image caching fixed
    - Canon CRAW support added
- indigo_ccd_ica:
    - bug fixes for MacOS Catalina
    - Avoid AF property behaviour fixed
- indigo_ccd_fli: fix reopen issue
- indigo_mount_nexstar: park position can be specified by user
- indigo_mount_simulator: fix RA move when not tracking

## [2.0-108] - Wed Jan  1 2020

### Overall:
- webGUI: readonly switch support added

### Drivers:
- indigo_mount_synscan: many fixes including PC Direct mode and baud rate detection.
- indigo_mount_nexstar: support side of pier, update libnexstar.
- indigo_mount_temma: support side of pier, zenith sync and drive speed.
- indigo_ccd_gphoto2: small fixes.
- infigo_ccd_ptp: fix PTP transaction for USB 3.0.
