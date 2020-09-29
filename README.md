# DOSBoxDetoured
 
## Detours

For easy usage, install detours using `vcpkg install detours:x64-windows`.

But samples might come in handy at some point, so vanilla install is nice to have as well:

https://github.com/microsoft/detours/wiki/FAQ#compiling-with-detours-code

So, within `x64 Native Tools Command Prompt for VS 2019`, type `nmake`.

You might get `'sn' is not recognized as an internal or external command`.

This utility is in `.NET Framework 4.6.1 SDK` payload in Visual Studio Installer.

In aforementioned prompt, type `path=%path%;C:\Program Files (x86)\Microsoft SDKs\Windows\v10.0A\bin\NETFX 4.6.1 Tools\x64` then `nmake` should work and you'll get the samples.

## Hooking

The function `NtVdm64CreateProcessInternalW` in `ntvdm64.dll` is used at `KernelBase.dll` in `CreateProcessInternalW`.

Rewriting that function is probably out of question, it's huge and for sure there will be many traps, if possible at all.

Ideas:

- rename imported function (`NtVdm64CreateProcessInternalW`) in `KernelBase.dll` ?
- hook into `NtVdm64CreateProcessInternalW` as soon as it's loaded by `KernelBase.dll` ?
  - not sure if possible at all and how it could be done

### Addendum

Actually, `NtVdm64RaiseInvalid16BitError` is also indirectly called in `Kernel32.dll`, it is called by `RaiseInvalid16BitExeError` which in turn is called by `BasepProcessInvalidImage`.

## Notes

Process Explorer finds absolutely nothing about `ntvdm64.dll` when the `16-bit application not supported...` message is visible.

It might be tempting to create a C++/CLI project but apparently this isn't the best thing to do:

https://docs.microsoft.com/en-us/cpp/dotnet/initialization-of-mixed-assemblies?redirectedfrom=MSDN&view=vs-2019
