cmake_minimum_required(VERSION 3.6)
project(rtv1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework Appkit")

set(SOURCE_FILES
        rtv1.h
        src/main.c

        src/create_image.c

        src/create_win.c

        src/init_pos_screen.c

        src/put_pixel.c

        src/v_oper/add.c
        src/v_oper/sub.c
        src/v_oper/scalar_mult.c
        src/v_oper/mult.c
        src/emit_rays.c
        src/v_oper/div.c
        src/v_oper/module.c
        src/v_oper/normal.c
        src/v_oper/v_copy.c
        src/v_oper/new_vector.c

        src/events/buttons.c

        src/intersects/intersect.c
        src/intersects/intersect_ray_sphere.c
        src/intersects/intersect_ray_plane.c
        src/intersects/intersect_ray_cylinder.c

        src/discriminant.c

        src/objects/create_obj.c
        src/objects/create_sphere.c
        src/objects/create_plane.c
        src/objects/create_cylinder.c
        src/objects/fill_objects.c)

add_executable(rtv1 ${SOURCE_FILES})