#!/usr/bin/env bash
# Minimal ESP32-S3 setup under ~/projects/greenbot-vision
# Usage: bash setup_greenbot.sh
set -euo pipefail

# -----------------------------
# Config
# -----------------------------
BASE_DIR="$HOME/projects/greenbot-vision"   # <--- all files live here
IDF_VERSION="v5.3.4"   # recommended latest stable                
CHIP="esp32s3"                              # Target chip
IDF_DIR="$BASE_DIR/esp-idf"                 # Framework
WORKSPACE="$BASE_DIR/workspace"             # Projects

# -----------------------------
# Helpers
# -----------------------------
say() { printf "\033[1;32m[SETUP]\033[0m %s\n" "$*"; }

# -----------------------------
# 1) Prepare folders
# -----------------------------
say "Creating project root at $BASE_DIR"
mkdir -p "$WORKSPACE"
cd "$BASE_DIR"

# -----------------------------
# 2) Clone ESP-IDF (if needed)
# -----------------------------
if [ -d "$IDF_DIR/.git" ]; then
  say "ESP-IDF already present at $IDF_DIR"
else
  say "Cloning ESP-IDF ($IDF_VERSION)"
  git clone --depth 1 -b "$IDF_VERSION" https://github.com/espressif/esp-idf.git "$IDF_DIR"
fi

# -----------------------------
# 3) Override ESP-IDF's default tool path
# -----------------------------
export IDF_TOOLS_PATH="$BASE_DIR/tools"
mkdir -p "$IDF_TOOLS_PATH"

# -----------------------------
# 4) Install tools
# -----------------------------
say "Installing tools for $CHIP into $IDF_TOOLS_PATH"
cd "$IDF_DIR"
./install.sh "$CHIP"

# -----------------------------
# 5) Export environment
# -----------------------------
say "Exporting ESP-IDF environment"
# shellcheck disable=SC1091
. "$IDF_DIR/export.sh"

# -----------------------------
# 6) Copy hello_world example
# -----------------------------
EX_DIR="$WORKSPACE/hello_world"
if [ ! -d "$EX_DIR" ]; then
  say "Copying hello_world to $EX_DIR"
  cp -R "$IDF_DIR/examples/get-started/hello_world" "$EX_DIR"
fi

cd "$EX_DIR"
idf.py set-target "$CHIP"
idf.py build

say "✅ Setup complete! Everything is inside:"
echo "   $BASE_DIR"
echo ""
echo "Next time, run:"
echo "   source $IDF_DIR/export.sh"
echo "   cd $EX_DIR"
echo "   idf.py build"
echo "   idf.py -p <YOUR_SERIAL_PORT> flash monitor"
