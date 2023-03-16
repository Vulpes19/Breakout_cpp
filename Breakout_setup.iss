; -- Example1.iss --

[Setup]
AppName=Breakout
AppVersion=1
AppPublisher="Ayman Baioumy"
AppPublisherURL="https://github.com/Vulpes19"
WizardStyle=modern
DefaultDirName={autopf}\Breakout game
DefaultGroupName=Game
UninstallDisplayIcon={app}\uninbr.exe
Compression=lzma2
SolidCompression=yes
OutputDir=userdocs:Inno Setup Examples Output
//WizardImageFile=
//WizardSmallImageFile=
//SetupIconFile=
WizardSmallImageBackColor=clNavy
WizardImageBackColor=clNavy
AppCopyright="This is a fan-made project all its components are my original work except for fonts and audio. All copyrights belong to the original owners of the Breakout game"

[Files]
Source: "C:\Users\asus\Documents\C++ games\Breakout\breakout.exe"; DestDir: "{app}"
Source: "C:\Users\asus\Documents\C++ games\Breakout\*"; DestDir: "{app}"
Source: "C:\Users\asus\Documents\C++ games\Breakout\*"; DestDir: "{app}"; Flags: recursesubdirs

[Icons]
Name: "{group}\Breakout"; Filename: "{app}\brk.exe"

[Types]
Name: "Breakout"; Description: "A simple remake of the famous arcade game Breakout from 1976"

[Tasks]
Name: "desktopicon"; Description: "Create a &desktop icon"
//Name: "desktopicon"; Flags: exclusive unchecked

[Languages]
Name: "en"; MessagesFile:"compiler:Default.isl"
Name: "fr"; MessagesFile:"compiler:Languages\French.isl"

[Run]
Filename: "{app}\breakout.exe"; Description: "Launch Game"; Flags: postinstall nowait
