fn main() {
    let manifest_dir = std::env::var("CARGO_MANIFEST_DIR").unwrap();
    println!("cargo:rustc-link-search=native={}/../build/", manifest_dir);
    println!("cargo:rustc-link-lib=static=plugin");
}
