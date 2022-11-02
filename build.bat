@echo off

ctime -begin physics2d.ctm

set CompilerFlags= /Zi /MDd /FC /nologo
REM set LinkerFlags=-subsystem:Console

IF NOT EXIST build (
    mkdir build
    pushd build

    cl %CompilerFlags% /c /D PLATFORM_DESKTOP /I..\src\external\glfw\include ^
        ..\src\rcore.c ^
        ..\src\rmodels.c ^
        ..\src\raudio.c ^
        ..\src\rglfw.c ^
        ..\src\rshapes.c ^
        ..\src\rtext.c ^
        ..\src\rtextures.c ^
        ..\src\utils.c
)

pushd build

cl %CompilerFlags% ^
    ..\main.cpp ^
    rcore.obj ^
    rmodels.obj ^
    raudio.obj ^
    rglfw.obj ^
    rshapes.obj ^
    rtext.obj ^
    rtextures.obj ^
    utils.obj ^
    /I ..\include/ /link /FORCE:MULTIPLE -incremental:no %LinkerFlags% -out:physics2d.exe ^
    Gdi32.lib ^
    winmm.lib ^
    user32.lib ^
    shell32.lib

popd

ctime -end physics2d.ctm
