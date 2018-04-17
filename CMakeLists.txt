SET(PROJECT_NAME DSO)
PROJECT(${PROJECT_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 2.6)
set(BUILD_TYPE Release)
set(EXECUTABLE_OUTPUT_PATH bin)
set(LIBRARY_OUTPUT_PATH lib)

# set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

# required libraries
# find_package(SuiteParse REQUIRED)
# find_package(Eigen3 REQUIRED)
# find_package(Boost COMPONENTS system thread) 

# flags
# add_definitions("-DENABLE_SSE")

set(CMAKE_CXX_FLAGS
#    "${SSE_FLAGS} -O3 -g -std=c++0x -march=native"
  "${CMAKE_CXX_FLAGS} -O3 -g -std=c++0x -mfpu=neon-vfpv4 -march=armv7-a -mfloat-abi=hard -fno-omit-frame-pointer")  

message(${CMAKE_CXX_FLAGS})
#-fPIC

set(Boost_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/thirdparty/boost")
set(Boost_LINK_LIBRARIES "${PROJECT_SOURCE_DIR}/thirdparty/boost/stage/lib")

# set(BOOST_THREAD_LIBRARY "${Boost_LINK_LIBRARIES}/libboost_thread.a")
# set(BOOST_SYSTEM_LIBRARY "${Boost_LINK_LIBRARIES}/libboost_system.a")

set(BOOST_THREAD_LIBRARY boost_thread)
set(BOOST_SYSTEM_LIBRARY boost_system)

# eigen3 add 
set(Eigen_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/thirdparty/eigen3")

set(SuiteSparse_LINK_LIBRARIES "${PROJECT_SOURCE_DIR}/thirdparty/SuiteSparse/lib")
set(SuiteSparse_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/thirdparty/SuiteSparse/include")





set(OpenCV_INCLUDE_DIRS "${PROJECT_SOURCE_DIR}/thirdparty/opencv/include")
set(OpenCV_LINK_LIBRARIES "${PROJECT_SOURCE_DIR}/thirdparty/opencv/lib_arm")


SET(OpenCV_LIB_COMPONENTS opencv_videostab;opencv_videoio;opencv_video;opencv_superres;opencv_stitching;opencv_shape;opencv_photo;opencv_objdetect;opencv_ml;opencv_imgcodecs;opencv_highgui;opencv_flann;opencv_features2d;opencv_calib3d)
foreach(__cvcomponent ${OpenCV_LIB_COMPONENTS})
  set(OpenCV_LIBS ${OpenCV_LIBS} "${__cvcomponent}")
endforeach()
message(${OpenCV_LIBS})


include_directories(
  ${Boost_INCLUDE_DIRS}	
  ${OpenCV_INCLUDE_DIRS}	
  ${Eigen_INCLUDE_DIRS}
  ${SuiteSparse_INCLUDE_DIRS}
  ${PROJECT_SOURCE_DIR}/src
  ${PROJECT_SOURCE_DIR}/src/include
  ${PROJECT_SOURCE_DIR}/thirdparty/Sophus
  ${PROJECT_SOURCE_DIR}/thirdparty/sse2neon
) 

link_directories(
  ${Boost_LINK_LIBRARIES}
  ${SuiteSparse_LINK_LIBRARIES}
  ${OpenCV_LINK_LIBRARIES}
)


# Sources files
set(dso_SOURCE_FILES
  ${PROJECT_SOURCE_DIR}/src/FullSystem/FullSystem.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/FullSystemOptimize.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/FullSystemOptPoint.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/FullSystemDebugStuff.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/FullSystemMarginalize.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/Residuals.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/CoarseTracker.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/CoarseInitializer.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/ImmaturePoint.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/HessianBlocks.cpp
  ${PROJECT_SOURCE_DIR}/src/FullSystem/PixelSelector2.cpp
  ${PROJECT_SOURCE_DIR}/src/OptimizationBackend/EnergyFunctional.cpp
  ${PROJECT_SOURCE_DIR}/src/OptimizationBackend/AccumulatedTopHessian.cpp
  ${PROJECT_SOURCE_DIR}/src/OptimizationBackend/AccumulatedSCHessian.cpp
  ${PROJECT_SOURCE_DIR}/src/OptimizationBackend/EnergyFunctionalStructs.cpp
  ${PROJECT_SOURCE_DIR}/src/util/settings.cpp
  ${PROJECT_SOURCE_DIR}/src/util/Undistort.cpp
  ${PROJECT_SOURCE_DIR}/src/util/globalCalib.cpp
)




set(HAS_PANGOLIN 0)
set(SEND_DSO_MAVLINK 
	${PROJECT_SOURCE_DIR}/src/sender_receiver.cpp 
	${PROJECT_SOURCE_DIR}/src/briMavlink.cpp
	${PROJECT_SOURCE_DIR}/src/quat_euler.cpp) 

set(HAS_OPENCV 0)
set(dso_opencv_SOURCE_FILES 
	${PROJECT_SOURCE_DIR}/src/IOWrapper/ImageDisplay_dummy.cpp
	${PROJECT_SOURCE_DIR}/src/IOWrapper/ImageRW_dummy.cpp)







# compile main library.
# include_directories( ${CSPARSE_INCLUDE_DIR} ${CHOLMOD_INCLUDE_DIR}) 

add_library(dso  SHARED ${dso_SOURCE_FILES} ${dso_opencv_SOURCE_FILES} )
target_link_libraries(dso ${BOOST_SYSTEM_LIBRARY} ${BOOST_THREAD_LIBRARY} cxsparse) 

add_library(optic SHARED src/fakeoptic.cpp ${SEND_DSO_MAVLINK})
target_link_libraries(optic dso ${OpenCV_LIBS})








# message("--- compiling dso_dataset.")
# add_executable(dso_dataset ${PROJECT_SOURCE_DIR}/src/main_dso_pangolin.cpp )
# target_link_libraries(dso_dataset dso ${BOOST_SYSTEM_LIBRARY} cxsparse ${BOOST_THREAD_LIBRARY})




