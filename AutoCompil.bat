@echo off
echo Demarrage de l'autocompilation et du televersement...

REM Utilisation de 'where' pour trouver platformio automatiquement
for /f "tokens=*" %%i in ('where platformio 2^>nul') do set PLATFORMIO_PATH=%%i

if "%PLATFORMIO_PATH%"=="" (
    echo PlatformIO non trouve. Assurez-vous qu'il est installe et dans le PATH.
    pause
    exit /b 1
)

echo Compilation du projet...
"%PLATFORMIO_PATH%" run
if %ERRORLEVEL% NEQ 0 (
    echo Erreur lors de la compilation.
    pause
    exit /b %ERRORLEVEL%
)

echo Televersement du code...
"%PLATFORMIO_PATH%" run --target upload
if %ERRORLEVEL% NEQ 0 (
    echo Erreur lors du televersement.
    pause
    exit /b %ERRORLEVEL%
)

echo Autocompilation et televersement termines avec succès.
pause
