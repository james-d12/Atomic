function(SetBuildTypeOptions project_name)
    if(CMAKE_BUILD_TYPE MATCHES Debug)
        message("-- Debug mode is enabled for ${project_name}.")
        add_compile_definitions(ATOMIC_DEBUG)
    elseif(CMAKE_BUILD_TYPE MATCHES Release)
        message("-- Release mode is enabled for ${project_name}.")
    endif()
endfunction()