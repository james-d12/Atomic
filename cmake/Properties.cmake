function(SetProjectProperties project_name standard)
    message("-- CXX Standard set to C++${standard} for ${project_name}.")

    set_target_properties(${project_name} PROPERTIES
        CXX_STANDARD ${standard}
        CXX_STANDARD_REQUIRED TRUE  
        CXX_EXTENSIONS FALSE
    )
endfunction()