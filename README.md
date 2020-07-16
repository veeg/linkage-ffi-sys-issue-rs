# Linkage ffi sys issue between C and Rust

This repository contains proof of concept FFI linkage issue that I cannot replicate
to generate the same external behaviour in Rust.

NOTE: This abstraction and library is only designed and implemented for a unix platform.

## Goal

A plugin based infrastructure that dynamically resolves symbols (`loader`) from plugins authors
(`plugin-user-c`/`plugin-user-rs`) that implements an API provided by `libplugin-c`.
This library includes some nifty magic to force the linker for the plugin authors to include
a symbol (`plugin_version`) by stubbing out its usage in the plugin, and only presenting the
plugin library as an archive.
This way, all symbols used by the plugin must copy all symbols it uses over into its own translation
unit.

## Problem

In C-land, the linker will happily create a global symbol in the `.dynsym` tab for the symbol
we desire. This is not the case for the rust generated shared library (cdylib).

We can easily verify this by inspecting the output of `readelf -Ws {so}` and inspecting the symbol (or lack thereof) in the `.dynsym` table.

## Test

Just run the `./run` script, and it will compile everything and run a test.
