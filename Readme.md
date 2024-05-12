# Raytracer

Your CPU goes brrrrr!

## Description
This repository contains the source code for the Raytracer project at Epitech, a 3D rendering software that simulates the path of light to generate realistic images. It utilizes advanced rendering techniques such as ray tracing, material modeling, shadows, reflections, and refractions to produce high-quality renders.

# Table of Contents

- [Description](#Description)
- [Usage](#Usage)
- [Features](#Features)
    - [Mandatory Features](#Mandatory-Features)
    - [Should Features](#Should-Features)
    - [Could Features](#Could-Features)
- [Scene File Format](#scene-file-format)
  - [Camera Parameters](#camera-parameters)
  - [Primitives Parameters](#primitives-parameters)
  - [Lights Parameters](#lights-parameters)
  - [Materials Parameters](#materials-parameters)
- [Tools](#tools)
- [Development Team](#development-team)

## Usage
```bash
./raytracer <SCENE_FILE>
```

**SCENE_FILE**: scene configuration

## Mandatory Features
- **Primitives**:
    - [x] Sphere
    - [x] Plane
- **Transformations**:
    - [x] Translation
- **Light**:
    - [x] Directional light
    - [x] Ambient light
- **Material**:
    - [x] Flat color
- **Scene configuration**:
    - [x] Add primitives to scene
    - [x] Set up lighting
    - [x] Set up camera
- **Interface**:
    - [x] No GUI, output to a PPM file

## Should Features
Once the previous features are working properly, you should add the following ones:
- **Primitives**:
    - [x] Cylinder
    - [x] Cone
- **Transformation**:
  - [x] Rotation
- **Light**:
    - [x] Drop shadows

## Could Features
- **Primitives**:
    - [x] Limited cylinder 
    - [x] Limited cone 
    - [ ] Torus 
    - [ ] Tanglecube 
    - [ ] Triangles 
    - [ ] .OBJ file 
    - [ ] Fractals 
    - [ ] Möbius strip 
- **Transformations**:
    - [x] Scale 
    - [ ] Shear 
    - [ ] Transformation matrix 
    - [ ] Scene graph 
- **Light**:
    - [x] Multiple directional lights 
    - [ ] Multiple point lights 
    - [x] Colored light 
    - [ ] Phong reflection model 
    - [ ] Ambient occlusion 
- **Material**:
    - [x] Transparency 
    - [x] Refraction 
    - [x] Reflection 
    - [x] Texturing from file 
    - [x] Texturing from procedural generation of chessboard 
    - [ ] Texturing from procedural generation of Perlin noise 
    - [ ] Normal mapping 
- **Scene configuration**:
    - [ ] Import a scene in a scene 
    - [ ] Set up antialiasing through supersampling 
    - [ ] Set up antialiasing through adaptative supersampling 
- **Optimizations**:
    - [ ] Space partitionning 
    - [x] Multithreading 
    - [ ] Clustering
- **Interface**:
    - [x] Display the image during and after generation 
    - [x] Exit during or after generation 
    - [x] Scene preview using a basic and fast renderer 
    - [x] Automatic reload of the scene at file change 

## Scene File Format
Scene file is a simple text file containing the configuration of the scene. It is divided into four sections: camera, primitives, lights, and materials.

In each section, you can define multiple elements. For example, you can define multiple spheres in the primitives section.

> Some parameters are mandatory, while others are optional. The mandatory parameters are required for the program to work correctly. The optional parameters are used to customize the scene further.
<details>
  <summary>Camera Parameters</summary>

- **fieldOfView**: Field of view of the camera
- **resolution_width**: Width of the image
- **resolution_height**: Height of the image
- **position_x**: X position of the camera
- **position_y**: Y position of the camera
- **position_z**: Z position of the camera
- **rotation_x**: X rotation of the camera
- **rotation_y**: Y rotation of the camera
- **rotation_z**: Z rotation of the camera
_Exemple:_
```cpp
camera :
{
    cameras = (
        { fieldOfView = 72.0; resolution_width = 1920; resolution_height = 1080; position_x = 0; position_y = -100; position_z = 20; rotation_x = 0; rotation_y = 0; rotation_z = 0; }
    );
};
```
</details>

<details>
  <summary>Primitives Parameters</summary>

Depending on the type of primitive, the parameters will change. Here some examples:
- **Sphere**:
    - **x**: X position of the sphere
    - **y**: Y position of the sphere
    - **z**: Z position of the sphere
    - **r**: Radius of the sphere
    - **color_r**: Red color of the sphere
    - **color_g**: Green color of the sphere
    - **color_b**: Blue color of the sphere
- **Plane**:
  - **axis**: Axis of the plane (X, Y, Z)
  - **position**: Position of the plane
  - **color_r**: Red color of the plane
  - **color_g**: Green color of the plane
  - **color_b**: Blue color of the plane

_Exemple:_
```cpp
primitives :
{
    spheres = (
        { x = 60; y = 5; z = 40; r = 25; color_r = 255; color_g = 64; color_b = 64; },
        { x = -40; y = 20; z = -10; r = 35; color_r = 64; color_g = 255; color_b = 64; }
    );

    planes = (
        { axis = "Z"; position = -20; color_r = 64; color_g = 64; color_b = 255; }
    );
};
```
</details>

<details>
  <summary>Lights Parameters</summary>

- **ambient**: Ambient light intensity
- **diffuse**: Diffuse light intensity
- **point_x**: X position of the point light
- **point_y**: Y position of the point light
- **point_z**: Z position of the point light

_Exemple:_
```cpp
lights :
{
    lights = (
        { ambient = 0.4; diffuse = 0.6; point_x = 400; point_y = 100; point_z = 500; }
    );
    directional = () ;
};
```
</details>

<details>
  <summary>Materials Parameters</summary>

- **name**: Name of the material
- **ambient**: Ambient light intensity of the material
- **diffuse**: Diffuse light intensity of the material
- **specular**: Specular light intensity of the material
- **shininess**: Shininess of the material
- **reflection**: Reflection intensity of the material
- **refraction**: Refraction intensity of the material
- **transparency**: Transparency intensity of the material
_Exemple:_
```cpp
materials :
{
    materials = (
        { name = "default"; ambient = 0.1; diffuse = 0.9; specular = 0.9; shininess = 100; },
        { name = "mirror"; ambient = 0.1; diffuse = 0.1; specular = 0.9; shininess = 100; reflection = 0.9; }
    );
};
```
</details>

## Tools
- **Language**: C++
- **Libraries**: libconfig++
- **Build**: CMake
- **Version Control**: Git
- **Continuous Integration**: GitHub Actions

## Development Team
- Sebastien BERTIL-SOUCHET (@Sebabacou)
- Ewen EMERAUD (@ewen1507)
- Alexis BOITEL (@DiaboloAB)
- Jules DANET (@fry56)

