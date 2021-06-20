add_executable(ppm_gen
	ppm_gen.c
#    ${PPM_SIG}
)

target_link_libraries(ppm_gen
                      pico_stdlib )
pico_add_extra_outputs(ppm_gen)
