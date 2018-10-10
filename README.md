# CPython

Visual Studio 로 Python용 C++ 확장 만들기 (<a href="https://docs.microsoft.com/ko-kr/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2017">https://docs.microsoft.com/ko-kr/visualstudio/python/working-with-c-cpp-python-in-visual-studio?view=vs-2017</a>)


에러 났던 부분
: LINK : fatal error LNK1158: cannot run 'rc.exe' <a href="https://stackoverflow.com/questions/14372706/visual-studio-cant-build-due-to-rc-exe">https://stackoverflow.com/questions/14372706/visual-studio-cant-build-due-to-rc-exe </a>

program files(x86)\Windows tollkit\10\10.017~\x86\rc.exe 와 rcdll.dll 파일을 복사해서 Visual Studio 14.0\VC\bin 아래로 넣어줌! 그 다음엔 잘 됨!
