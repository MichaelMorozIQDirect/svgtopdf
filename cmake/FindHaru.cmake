find_path(HARU_INCLUDE_DIR hpdf.h)
find_library(HARU_LIBRARY NAMES hpdf)

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(Haru
	REQUIRED_VARS HARU_LIBRARY HARU_INCLUDE_DIR
)

if(HARU_FOUND AND NOT TARGET Haru::hpdf)
	add_library(Haru::hpdf UNKNOWN IMPORTED)
	set_target_properties(Haru::hpdf PROPERTIES
		IMPORTED_LINK_INTERFACE_LANGUAGES "C"
		IMPORTED_LOCATION "${HARU_LIBRARY}"
		INTERFACE_INCLUDE_DIRECTORIES "${HARU_INCLUDE_DIR}"
	)
endif()

