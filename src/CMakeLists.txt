kdevplatform_add_plugin(piasimov
    JSON piasimov.json
    SOURCES piasimov.cpp
)

target_link_libraries(piasimov
    KDev::Interfaces
)
