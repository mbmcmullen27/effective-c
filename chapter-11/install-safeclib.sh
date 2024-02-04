#!/usr/bin/env bash

set -o errexit -o nounset -o pipefail

# Safeclib version.
SAFECLIB_VERSION="3.7.1"

# Check if a command exists.
check_command() {
  if ! command -v "$1" &>/dev/null; then
    echo "Error: $1 is not installed." >&2
    exit 1
  fi
}

# Download and extract safeclib.
download() {
  local package="safeclib-${SAFECLIB_VERSION}.tar.gz"
  local url="https://github.com/rurban/safeclib/releases/download/v${SAFECLIB_VERSION}/${package}"

  echo "Downloading safeclib ${SAFECLIB_VERSION}..."
  curl -fsSLO "${url}"
  tar -xf "${package}"

  rm "${package}"
}

# Build and install safeclib.
build_and_install() {
  local directory="safeclib-${SAFECLIB_VERSION}"

  pushd "${directory}"

  echo "Building and installing safeclib..."
  autoreconf -Wall --install && ./configure && make
  make install

  popd
}

# Update config.
update_config() {
  echo "Updating config..."
  ldconfig
}

# Clean up.
cleanup() {
  echo "Cleaning up..."
  find . -maxdepth 1 -type d -name "safeclib-*" -exec rm -rf {} \;
}

# Main function.
main() {
  # Check if required commands are installed.
  check_command curl
  check_command tar
  check_command autoreconf
  check_command ldconfig
  check_command automake

  # Build and install safeclib.
  download
  build_and_install
  update_config
  cleanup

  echo "safeclib ${SAFECLIB_VERSION} installed successfully"
}

main "$@"
