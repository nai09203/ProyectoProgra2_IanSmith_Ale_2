cmake_minimum_required(VERSION 4.1)
project(ProyectoProgra2_IanSmith_Ale_)

set(CMAKE_CXX_STANDARD 20)

add_executable(ProyectoProgra2_IanSmith_Ale_ main.cpp
        ProyectException.hpp
        ArchivoInvalido.hpp
        FormatoInvalido.hpp
        ErrorGeneral.hpp
        Incidencia.cpp
        Incidencia.h
        ValidadorEquipo.cpp
        ValidadorEquipo.h
        ValidadorIncidencia.cpp
        ValidadorIncidencia.h
        Equipo.cpp
        Equipo.h
        CalcularPrioridad.cpp
        CalcularPrioridad.h
        EjecutorMantenimiento.cpp
        EjecutorMantenimiento.h
        MicroscopioLab.cpp
        MicroscopioLab.h
        ComputadoraLab.cpp
        ComputadoraLab.h
        Mantenimiento.h
        MantenimientoBase.cpp
        MantenimientoBase.h
        MantenimientoDecorator.cpp
        MantenimientoDecorator.h
        LimpiezaDeco.cpp
        LimpiezaDeco.h
        CalibrarDeco.cpp
        CalibrarDeco.h
        RevisionDeco.cpp
        RevisionDeco.h
        ValidadorArchivos.cpp
        ValidadorArchivos.h
        GestorArchivos.cpp
        GestorArchivos.h
        TextEquipo.cpp
        TextEquipo.h
        TextIncidencia.cpp
        TextIncidencia.h
        OrdenadorEquipos.cpp
        OrdenadorEquipos.h
        Planificador.cpp
        Planificador.h
        Reportador.cpp
        Reportador.h
        FabricaMantenimiento.cpp
        FabricaMantenimiento.h
        Simulador.cpp
        Simulador.h)
