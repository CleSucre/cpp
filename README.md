# C++ For 42 school

## Introduction

This repository contains the C++ projects I did during my time at 42 school. The projects are done in C++ and are based on the subject given by the school.

Note: The projects are done in C++98, if you are an experienced C++ developer, you might find this projects outdated.

## Projects

- [**CPP Module 00**](./CPP_Module_00): Namespace, class, member functions, stdio stream, initialization lists, static, const, and lots of basic stuff

- [**CPP Module 01**](./CPP_Module_01): Memory allocation, references, pointers to members, switch

- [**CPP Module 02**](./CPP_Module_02): Ad-hoc polymorphism, operators overload and orthodox canonical classes


## Usage

Each project contains a subject with the instructions to follow. The subject is in the `resources` folder.

### Running the code on docker

I had enough of switching between MacOS, Linux and Windows, so I decided to use docker to run my code.

To run the code on docker, you can use the following command:

```bash
docker-compose up --build -d
```

To enter the container, you can use the following command:

```bash
docker-compose exec cpp bash
```

