#################################################################
cmake_minimum_required (VERSION 2.6 FATAL_ERROR)
#set (CMAKE_VERBOSE_MAKEFILE ON)

set (App_Name "SDL2_PONG")
if(App_Name STREQUAL "")
	message(FATAL_ERROR "You Must set the App_Name varable")
endif()

project (${App_Name})

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")


##################################################################

set (Build_Dir_OK "TRUE")
string (REGEX MATCH "^${CMAKE_SOURCE_DIR}" In_Sub_Dir ${CMAKE_BINARY_DIR})
if (In_Sub_Dir)
  string (REGEX MATCH "^${CMAKE_SOURCE_DIR}" In_Build_Dir ${CMAKE_BINARY_DIR})
  if (NOT In_Build_Dir)
    set (Build_Dir_OK "FALSE")
  endif ()
endif ()

if (NOT Build_Dir_OK)
  message (FATAL_ERROR "You must run cmake from a directory that is not in your source tree, or that is in a special subdirectory of the tree whose name begins with ‘build’.")
endif ()

###########################################################################


if (CMAKE_BUILD_TYPE STREQUAL "")
	set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Choose the type of build, options are: None Debug Release RelWithDebInfo MinSizeRel." FORCE)
endif()

###############################################################################

file(GLOB game_files src/*.c src/*.cpp src/*.h src/*.hpp)

file(GLOB renderer_files src/Renderer/*.h src/Renderer/*.cpp)

file(GLOB baseClasses_files src/BaseClasses/*.h src/BaseClasses/*.cpp)

file(GLOB physics_files src/Physics/*.h src/Physics/*.cpp)

SOURCE_GROUP(Renderer FILES ${renderer_files})

SOURCE_GROUP(Game FILES ${game_files})

SOURCE_GROUP(BaseClasses FILES ${baseClasses_files})

SOURCE_GROUP(Physics FILES ${physics_files})



link_directories(
)

include_directories(
	${CMAKE_SOURCE_DIR}/include
	)

if(WIN32)
	add_executable(${App_Name} WIN32
        ${game_files}
        ${baseClasses_files}
        ${renderer_files}
        ${physics_files}
	)

	SET_TARGET_PROPERTIES(${App_Name} PROPERTIES COMPILE_FLAGS "/Od /ZI")
	SET_TARGET_PROPERTIES(${App_Name} PROPERTIES LINK_FLAGS "/DEBUG")

else ()
	add_executable (${App_Name}
        ${game_files}
        ${baseClasses_files}
        ${renderer_files}
        ${physics_files}
	)
	if(CMAKE_COMPILER_IS_GNUCXX)
		set(CMAKE_CXX_FLAGS "-Wno-write-strings")   
	endif()

endif ()

target_link_libraries(${App_Name}
)

#################################################################3


option(Option_SDL_Dev "" ON)

if (Option_SDL_Dev)
	find_package(SDL2)
	if (NOT SDL2_FOUND)
		message (FATAL_ERROR "SDL not found!")
	endif (NOT SDL2_FOUND)

	find_package(SDL2_image)
	if (NOT SDL2IMAGE_FOUND)
		message (FATAL_ERROR "SDL_Image not found!")
	endif (NOT SDL2IMAGE_FOUND)

	find_package(SDL2_ttf)
	if (NOT SDL2TTF_FOUND)
		message (FATAL_ERROR "SDL_ttf not found!")
	endif (NOT SDL2TTF_FOUND)

	find_package(SDL2_mixer)
	if (NOT SDL2MIXER_FOUND)
		message (FATAL_ERROR "SDL_mixer not found!")
	endif (NOT SDL2MIXER_FOUND)

	include_directories(
		${SDL2_INCLUDE_DIR}
		${INCLUDE_DIRECTORIES}
		)
	target_link_libraries(${App_Name}
		${SDL2_LIBRARY}
 		${SDL2MAIN_LIBRARY}
		${SDL2IMAGE_LIBRARY}
		${SDL2MIXER_LIBRARY}
		${SDL2MAIN_LIBRARY}
		${SDL2IMAGE_LIBRARY}
		${SDL2TTF_LIBRARY}
		${TARGET_LINK_LIBRARIES}
		)

endif(Option_SDL_Dev)

#message("${CMAKE_SOURCE_DIR}/Assets")
#message("${CMAKE_BINARY_DIR}")

file(COPY "${CMAKE_SOURCE_DIR}/Assets" DESTINATION "${CMAKE_BINARY_DIR}")




