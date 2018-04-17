SDK_DIR="/home/work/TS-SDK/sdkinstall"
[ -n "${SDKDIR}" ] && SDK_DIR="${SDKDIR}"

TOOLCHAIN_DIR="gcc-linaro-arm-linux-gnueabihf-4.8-2013.08_linux"

if [ ! -d "${SDK_DIR}" -o ! -d "${SDK_DIR}/sysroots" -o ! -d "${SDK_DIR}/${TOOLCHAIN_DIR}" ] ; then

echo ""
echo "Environment variable 'SDKDIR' is invalid!"
echo "Set"
echo "    SDKDIR=/where/is/your/sdk"
echo "before"
echo "    source scripts/envsetup.sh"
echo ""

else

export PATH="${SDK_DIR}/sysroots/x86_64-linux/usr/bin/cortexa8hf-vfp-neon-linux-gnueabi:${SDK_DIR}/sysroots/eagle8074/usr/bin/crossscripts:${SDK_DIR}/sysroots/x86_64-linux/usr/sbin:${SDK_DIR}/sysroots/x86_64-linux/usr/bin:${SDK_DIR}/sysroots/x86_64-linux/sbin:${SDK_DIR}/sysroots/x86_64-linux/bin:${SDK_DIR}/${TOOLCHAIN_DIR}/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/local/mnt/workspace/software/android-sdk-linux/tools:/local/mnt/workspace/software/android-sdk-linux/platform-tools:/usr/lib/git-core:/usr/lib/git-core"
export PKG_CONFIG_SYSROOT_DIR="${SDK_DIR}/sysroots/eagle8074"
export PKG_CONFIG_PATH="${SDK_DIR}/sysroots/eagle8074/usr/lib/pkgconfig:${SDK_DIR}/sysroots/eagle8074/usr/share/pkgconfig"
export SDKTARGETSYSROOT="${SDK_DIR}/sysroots/eagle8074"
export INC_TOOLCHAIN="${SDK_DIR}/${TOOLCHAIN_DIR}/arm-linux-gnueabihf/include"
export INC_KERNELHEADER="${SDKTARGETSYSROOT}/usr/include/linux-headers/usr/include"
export OECORE_NATIVE_SYSROOT="${SDK_DIR}/sysroots/x86_64-linux"
export OECORE_TARGET_SYSROOT="${SDK_DIR}/sysroots/eagle8074"
export OECORE_ACLOCAL_OPTS="-I ${SDK_DIR}/sysroots/x86_64-linux/usr/share/aclocal"
export CPATH="${SDK_DIR}/sysroots/eagle8074/usr/lib/:${SDK_DIR}/sysroots/eagle8074/usr/lib/media/:${SDK_DIR}/sysroots/eagle8074/usr/include/omx/:${SDK_DIR}/sysroots/eagle8074/usr/include/camera-hal/:${SDK_DIR}/sysroots/eagle8074/usr/include/live555:${SDK_DIR}/sysroots/eagle8074/usr/include/glib-2.0:${SDK_DIR}/sysroots/eagle8074/usr/lib/glib-2.0/include"
export CPLUS_INCLUDE_PATH="${SDK_DIR}/sysroots/eagle8074/usr/lib/:${SDK_DIR}/sysroots/eagle8074/usr/lib/media/:${SDK_DIR}/sysroots/eagle8074/usr/include/omx/:${SDK_DIR}/sysroots/eagle8074/usr/include/camera-hal/:${SDK_DIR}/sysroots/eagle8074/usr/include/live555:${SDK_DIR}/sysroots/eagle8074/usr/include/adreno200/:${SDK_DIR}/sysroots/eagle8074/usr/include/glib-2.0:${SDK_DIR}/sysroots/eagle8074/usr/lib/glib-2.0/include"
export CC="arm-linux-gnueabihf-gcc"
export CXX="arm-linux-gnueabihf-g++"
export CPP="arm-linux-gnueabihf-gcc -E"
export AS="arm-linux-gnueabihf-gcc"
export LD="arm-linux-gnueabihf-ld"
export GDB="arm-linux-gnueabihf-gdb"
export STRIP="arm-linux-gnueabihf-strip"
export RANLIB="arm-linux-gnueabihf-ranlib"
export OBJCOPY="arm-linux-gnueabihf-objcopy"
export OBJDUMP="arm-linux-gnueabihf-objdump"
export AR="arm-linux-gnueabihf-ar"
export NM="arm-linux-gnueabihf-nm"
export M4="m4"
export TARGET_PREFIX="arm-linux-gnueabihf-"
export CONFIGURE_FLAGS="--target=arm-linux-gnueabi --host=arm-linux-gnueabi --build=x86_64-linux --with-libtool-sysroot=$SDKTARGETSYSROOT"
export CFLAGS="-march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot=$SDKTARGETSYSROOT -isystem${INC_TOOLCHAIN} -isystem${INC_KERNELHEADER}"
export CXXFLAGS="-march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot=$SDKTARGETSYSROOT -isystem${INC_TOOLCHAIN} -isystem${INC_KERNELHEADER}"
export CPPFLAGS="-march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot=$SDKTARGETSYSROOT -isystem${INC_TOOLCHAIN} -isystem${INC_KERNELHEADER}"
export ASFLAGS="-march=armv7-a -mthumb-interwork -mfloat-abi=hard -mfpu=neon -mtune=cortex-a8 --sysroot=$SDKTARGETSYSROOT -isystem${INC_TOOLCHAIN} -isystem${INC_KERNELHEADER}"
export LDFLAGS="--sysroot=$SDKTARGETSYSROOT -L./usr/lib -L${SDK_DIR}/${TOOLCHAIN_DIR}/arm-linux-gnueabihf/lib -L$SDKTARGETSYSROOT/usr/lib"
export OECORE_DISTRO_VERSION="1.0"
export OECORE_SDK_VERSION="nodistro.0"
export ARCH=arm
export CROSS_COMPILE="arm-linux-gnueabihf-"
export ARM_ARCHITECTURE=True
fi
