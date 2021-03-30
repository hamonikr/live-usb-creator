# Live USB Creator

ISO 이미지로 쓰기 가능한 라이브 USB를 제작하는 프로그램입니다.

- MXLinux 프로젝트에서 사용되는 live-usb-maker 를 하모니카에서 사용하도록 수정한 버전
- 제작된 USB 내 writable 폴더가 생기고 그 안에 자유롭게 데이터를 쓸 수 있습니다.
- 사용할 USB의 공간을 퍼센트로 지정할 수 있습니다. (남은 공간을 다른 파일시스템 용으로 사용 가능)

지원 : 하모니카 4.0

## Other OS
 
 * AppImage : https://github.com/MX-Linux/lum-qt-appimage/releases/tag/19.11.02

다운로드 받은 파일에 실행권한을 부여하고 다음과 같이 사용할 수 있습니다.
```
 sudo ./live-usb-maker-qt-19.11.02.x86_64.AppImage
```

## upstream projects

 * AppImage : https://github.com/MX-Linux/lum-qt-appimage
 * live-usb-maker CLI : https://github.com/BitJam/live-usb-maker
 * live-usb-maker-qt(GUI) : https://github.com/AdrianTM/mx-live-usb-maker

## Korean translation
 * https://github.com/chaeya/mx-live-usb-maker/blob/c9a50f331db561a7b3678fd9541a24e0c4280902/translations/mx-live-usb-maker_ko.ts

## Known Issue
 - Coudn't apply locale even add translate file.