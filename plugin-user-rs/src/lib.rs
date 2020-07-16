pub use libplugin_sys::plugin_version;

#[no_mangle]
fn _force_plugin_version_to_be_included(_arg: ::std::os::raw::c_void) {
    // Garbage arguments - meaningless
    let mut d2: std::os::raw::c_int = 0;
    let d2p: *mut std::os::raw::c_int = &mut d2;

    // Usage of version symbol from static archive, so we embed it into
    // our cdylib.
    unsafe {
        plugin_version(d2p);
    }
}
