add_library(io
        image_writer.cc
        portable_anymap_writer.cc
        image_reader.cc
        portable_anymap_reader.cc
)

target_link_libraries(io PRIVATE image)