let
  pkgs = import <nixpkgs> {};
  stdenv = pkgs.stdenv;
in
  stdenv.mkDerivation {
    name = "42-env-1.0.0";
    version = "1.0.0";
    buildInputs = [ pkgs.x11 pkgs.pkgconfig ];
  }
