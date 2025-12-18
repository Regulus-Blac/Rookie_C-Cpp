rem 合并 build.bat 和 run.bat：先构建，再在构建成功时运行可执行文件
@echo off
pushd .

rem 调用构建脚本（使用 call 保持当前批处理继续执行）
call "%~dp0build.bat"
rem 检查构建返回码，非 0 则退出并返回该码
if %ERRORLEVEL% NEQ 0 (
    echo Build failed with exit code %ERRORLEVEL%.
    popd
    exit /b %ERRORLEVEL%
)

rem 构建成功，调用运行脚本
call "%~dp0run.bat"
rem 将 run.bat 的返回码作为本脚本的返回码
set rc=%ERRORLEVEL%
popd
exit /b %rc%
