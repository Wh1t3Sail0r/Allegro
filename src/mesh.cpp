#include "mesh.h"

using namespace std;

mesh_t mesh = {
    .rotation = { .x = 0, .y = 0, .z = 0 }
};

vec3_t cube_vertices[N_CUBE_VERTICES] = {
    { .x = -1, .y = -1, .z = -1 }, // 1
    { .x = -1, .y =  1, .z = -1 }, // 2
    { .x =  1, .y =  1, .z = -1 }, // 3
    { .x =  1, .y = -1, .z = -1 }, // 4
    { .x =  1, .y =  1, .z =  1 }, // 5
    { .x =  1, .y = -1, .z =  1 }, // 6
    { .x = -1, .y =  1, .z =  1 }, // 7
    { .x = -1, .y = -1, .z =  1 }  // 8
};

face_t cube_faces[N_CUBE_FACES] = {
    // front
    { .a = 1, .b = 2, .c = 3, .color = red },
    { .a = 1, .b = 3, .c = 4, .color = red },
    // right
    { .a = 4, .b = 3, .c = 5, .color = yellow },
    { .a = 4, .b = 5, .c = 6, .color = yellow },
    // back
    { .a = 6, .b = 5, .c = 7, .color = green  },
    { .a = 6, .b = 7, .c = 8, .color = green  },
    // left
    { .a = 8, .b = 7, .c = 2, .color = blue  },
    { .a = 8, .b = 2, .c = 1, .color = blue  },
    // top
    { .a = 2, .b = 7, .c = 5, .color = purple  },
    { .a = 2, .b = 5, .c = 3, .color = purple  },
    // bottom
    { .a = 6, .b = 8, .c = 1, .color = pink  },
    { .a = 6, .b = 1, .c = 4, .color = pink  }
};

void load_cube_mesh_data() {

    // Loop through all cube vertices and push
    for(int i = 0; i < N_CUBE_VERTICES; i++) {
        mesh.vertices.push_back(cube_vertices[i]);
    }

    // Loop through all cube faces and push
    for(int i = 0; i < N_CUBE_FACES; i++) {
        mesh.faces.push_back(cube_faces[i]);
    }
}

void load_obj_mesh_data(string file) {

    // Read contents of obj file
    ifstream in_file1(file);
    // printf("%s\n", "Check 1");

    // Check if file was able to opened
    if (!in_file1) {
        cout << "Unable to open file " << file << endl;
        exit(1);   // call system to stop
    }

    // Assign some memory to the line that won't get filled (1024 characters max per line)
    string line1;

    // printf("%s\n", "Check 2");

    // Read vertices
    // Read the input from each line of the file into the line array
    while(getline(in_file1, line1)) {

        if(line1[0] == 'v' && line1[1] == ' ') {
            vec3_t vertex;
            // Read the format of the line and store values in vertex data
            // sscanf(line to read, format, where to store values - must be loaded by reference (&))
            // sscanf requires the line to read as a char array, so we need to convert to a c_string
            int len = line1.length();
            char line_to_read[len + 1];
            strcpy(line_to_read, line1.c_str());
            sscanf(line_to_read, "v %f %f %f", &vertex.x, &vertex.y, &vertex.z);
            mesh.vertices.push_back(vertex);
            // cout << mesh.vertices.back().x << " " << mesh.vertices.back().y << " " << mesh.vertices.back().z << endl;
        }
    }

    // printf("%s\n", "Check 3");

    ifstream in_file2(file);
    string line2;
    // Read faces
    // Read the input from each line of the file into the line array
    while(getline(in_file2, line2)) {

        if(line2[0] == 'f' && line2[1] == ' ') {

            int vertex_indices[4];
            int texture_indices[4];
            int normal_indices[4];
            // Read the format of the line and store values in face data
            // sscanf(line to read, format, where to store values - must be loaded by reference (&))
            // sscanf requires the line to read as a char array, so we need to convert to a c_string
            int len = line2.length();
            char line_to_read[len + 1];
            strcpy(line_to_read, line2.c_str());

            sscanf(
                line_to_read, "f %d/%d/%d %d/%d/%d %d/%d/%d",
                &vertex_indices[0], &texture_indices[0], &normal_indices[0],
                &vertex_indices[1], &texture_indices[1], &normal_indices[1],
                &vertex_indices[2], &texture_indices[2], &normal_indices[2]
            );

            // Load the vertex indices into the face data structure
            face_t face = {
                .a = vertex_indices[0],
                .b = vertex_indices[1],
                .c = vertex_indices[2],
                .color = gray
            };

            mesh.faces.push_back(face);
        }
    }
}
