# DOWNY 💯

Downy is a simple script that ams to simplify downloading audio or video by using [yt-dlp](https://github.com/yt-dlp/yt-dlp) and [ffmpeg](https://www.ffmpeg.org/) packages. This tool is very to use and is friendly for lambda user.
This tool is for unix-like operating system.

## Requirements 🔑
You need to install the following packages:
- [yt-dlp](https://github.com/yt-dlp/yt-dlp)
- [ffmpeg](https://www.ffmpeg.org)

## Installation 🚀 🚀
For now, you must install **downy** by compiling sources.
Requirements for compiling source:

### Ubuntu (based on Debian)
```sh
sudo apt update
sudo apt install build-essential
```

### Fedora (based on Red Hat0
To install a full set of development tools, including GCC and GNU Make
```sh
sudo dnf groupinstall "Development Tools"
```
Alternatively, if you just want GCC and Make:
```sh
sudo dnf install gcc make
```

### Arch linux
```sh
sudo pacman -S base-devel
```

### Gentoo (source-based)
```sh
sudo emerge sys-devl/gcc sys-devel/make
```

> Make sure that **gcc** and **make** are successfully installed.

```sh
gcc --version
make --version
```

Now,clone this repo:
```sh
git clone https://github.com/nf4r4r4n/downy_c
```
Compile the project:
```sh
make all clean
```

Copy the executable binary to system binaries:
```sh
sudo mv ./downy /bin/downy
```

Restart your terminal and make sure that is is there:
```sh
downy --version
```

That's it and enjoy.
Don't forget to star the project ✨✨😄.
