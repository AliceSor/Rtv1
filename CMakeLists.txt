
cmake_minimum_required(VERSION 3.6)
project(rtv1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -lmlx -framework OpenGL -framework Appkit")

set(SOURCE_FILES
        rtv1.h
        src/main.c

        src/create_image.c

        src/create_win.c

        src/points/init_pos_screen.c

        src/put_pixel.c

        src/v_oper/add.c
        src/v_oper/sub.c
        src/v_oper/scalar_mult.c
        src/v_oper/mult.c
        src/v_oper/div.c
        src/v_oper/module.c
        src/v_oper/normal.c
        src/v_oper/v_copy.c
        src/v_oper/new_vector.c

        src/events/buttons.c

        src/discriminant.c

        src/objects/create_obj.c
        src/objects/create_sphere.c
        src/objects/create_plane.c
        src/objects/create_cylinder.c
        src/objects/fill_objects.c
        src/objects/create_cone.c
        src/events/move_plane.c
        src/events/move_sphere.c
        src/events/move_cylinder.c
        src/events/move_cone.c
        src/objects/create_light.c
        src/color/integrate_color.c
        src/color/create_color.c
        src/points/for_each_point.c
        src/ray_trace.c
        src/intersects/intersects_objects.c
        src/intersects/some_calculating.c
        src/intersects/identify_obj.c
        src/intersects/find_hit_point.c
        src/intersects/find_nrml_light_ray.c
        src/light/find_diffuse.c
        src/color/calc_color.c
        src/light/find_specular.c
        src/events/move_x.c
        src/events/move_y.c
        src/events/move_z.c
        src/events/change_size.c
        src/events/change_speed.c
        src/points/move_forward.c src/points/move_back.c src/events/simple_move.c)

add_executable(rtv1 ${SOURCE_FILES})