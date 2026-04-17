<p align="center">
    <img src="media/logo.png" alt="analib" width="200"/>
</p>
  
<p align="center">
  <em>Opinionated header-only C library</em>
</p>
  
<p align="center">
    <img src="https://img.shields.io/badge/C_version-11-cyan?style=flat-square" alt="C version" />
    <img src="https://img.shields.io/badge/license-MIT-green?style=flat-square" alt="MIT License" />
  <img src="https://img.shields.io/github/last-commit/simon-danielsson/analib-c/main?style=flat-square&color=blue" alt="Last commit" />
</p>
  
<p align="center">
  <a href="#info">Info</a> •
  <a href="#usage">Usage</a> •
  <a href="#license">License</a>
</p>  

---
<div id="info"></div>

## Info
    
This library is built to house some of the most common utilities I make use of when building programs in C - I have chosen not to constrain the library to any specific utility or theme. 
  
> [!IMPORTANT]  
> Analib is a criminally opinionated library built to cater only to myself, and myself only. If you are not me, there is a good chance you will not enjoy using this library.
  
Inspiration has been taken from the following projects:  
- [sv.h](https://github.com/tsoding/sv)  
- [nob.h](https://github.com/tsoding/nob.h)  
  
---
<div id="usage"></div>

## Usage
  
Copy [analib.h](./analib.h) into your project and include it like this:  
  
```c
#define ANALIB_IMPLEMENTATION
#include "./analib.h"
```
  
You can de-activate all AL_db… functions using a definition before the include - useful if you want to bypass all debug logs, asserts and todos at once:

```c
#define AL_DEBUG_OFF
#define ANALIB_IMPLEMENTATION
#include "./analib.h"
```
  
---
<div id="license"></div>

## License
This project is licensed under the [MIT License](https://github.com/simon-danielsson/analib-c/blob/main/LICENSE).  
