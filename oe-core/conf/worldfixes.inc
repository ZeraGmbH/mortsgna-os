PREFERRED_PROVIDER_udev = "systemd"
PREFERRED_PROVIDER_virtual/fftw = "fftw"

# use gold
DISTRO_FEATURES_append = " ld-is-gold"

# use ptest
DISTRO_FEATURES_append = " ptest"

# use systemd
DISTRO_FEATURES_append = " systemd"
DISTRO_FEATURES_BACKFILL_CONSIDERED = "sysvinit"
VIRTUAL-RUNTIME_init_manager = "systemd"
VIRTUAL-RUNTIME_initscripts = ""

# use opengl
DISTRO_FEATURES_append = " opengl"

# use wayland to fix building weston and qtwayland
DISTRO_FEATURES_append = " wayland"

PREFERRED_PROVIDER_jpeg = "libjpeg-turbo"
PREFERRED_PROVIDER_jpeg-native = "libjpeg-turbo-native"
PREFERRED_PROVIDER_gpsd = "gpsd"
PREFERRED_PROVIDER_e-wm-sysactions = "e-wm"
ESYSACTIONS = "e-wm-sysactions"

# don't pull libhybris unless explicitly asked for
PREFERRED_PROVIDER_virtual/libgl ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles1 ?= "mesa"
PREFERRED_PROVIDER_virtual/libgles2 ?= "mesa"
PREFERRED_PROVIDER_virtual/egl ?= "mesa"

# to fix fsoaudiod, alsa-state conflict in shr-image-all
VIRTUAL-RUNTIME_alsa-state = ""
# to prevent alsa-state being pulled into -dev or -dbg images
RDEPENDS_${PN}-dev_pn-alsa-state = ""
RDEPENDS_${PN}-dbg_pn-alsa-state = ""

# to fix dependency on conflicting x11-common from packagegroup-core-x11
VIRTUAL-RUNTIME_xserver_common ?= "xserver-common"
RDEPENDS_${PN}-dev_pn-x11-common = ""
RDEPENDS_${PN}-dbg_pn-x11-common = ""

# to fix apm, fso-apm conflict in shr-image-all
VIRTUAL-RUNTIME_apm = "fso-apm"

# require conf/distro/include/qt5-versions.inc
# QT5_VERSION = "5.4.0+git%"

# for qtwebkit etc
# see https://bugzilla.yoctoproject.org/show_bug.cgi?id=5013
# DEPENDS_append_pn-qtbase = " mesa"
PACKAGECONFIG_append_pn-qtbase = " icu gl accessibility freetype fontconfig"

# qtwayland doesn't like egl and xcomposite-glx enabled at the same time
# http://lists.openembedded.org/pipermail/openembedded-devel/2016-December/110444.html
PACKAGECONFIG_remove_pn-qtwayland = "xcomposite-egl xcomposite-glx"

# for webkit-efl
PACKAGECONFIG_append_pn-harfbuzz = " icu"

inherit blacklist
# PNBLACKLIST[samsung-rfs-mgr] = "needs newer libsamsung-ipc with negative D_P: Requested 'samsung-ipc-1.0 >= 0.2' but version of libsamsung-ipc is 0.1.0"
PNBLACKLIST[android-system] = "depends on lxc from meta-virtualiazation which isn't included in my world builds"
PNBLACKLIST[bigbuckbunny-1080p] = "big and doesn't really need to be tested so much"
PNBLACKLIST[bigbuckbunny-480p] = "big and doesn't really need to be tested so much"
PNBLACKLIST[bigbuckbunny-720p] = "big and doesn't really need to be tested so much"
PNBLACKLIST[bigbuckbunny-720p] = "big and doesn't really need to be tested so much"
PNBLACKLIST[tearsofsteel-1080p] = "big and doesn't really need to be tested so much"
PNBLACKLIST[build-appliance-image] = "tries to include whole downloads directory in /home/builder/poky :/"

# enable reporting
# needs http://patchwork.openembedded.org/patch/68735/
ERR_REPORT_SERVER = "errors.yoctoproject.org"
ERR_REPORT_PORT = "80"
ERR_REPORT_USERNAME = "Martin Jansa"
ERR_REPORT_EMAIL = "Martin.Jansa@gmail.com"
ERR_REPORT_UPLOAD_FAILURES = "1"
INHERIT += "report-error"

# needs patch with buildstats-summary.bbclass
INHERIT += "buildstats buildstats-summary"

# be more strict with QA warnings, turn them all to errors:
ERROR_QA_append = " ldflags useless-rpaths rpaths staticdev libdir xorg-driver-abi             textrel already-stripped incompatible-license files-invalid             installed-vs-shipped compile-host-path install-host-path             pn-overrides infodir build-deps             unknown-configure-option symlink-to-sysroot multilib             invalid-packageconfig host-user-contaminated uppercase-pn"
WARN_QA_remove = " ldflags useless-rpaths rpaths staticdev libdir xorg-driver-abi             textrel already-stripped incompatible-license files-invalid             installed-vs-shipped compile-host-path install-host-path             pn-overrides infodir build-deps             unknown-configure-option symlink-to-sysroot multilib             invalid-packageconfig host-user-contaminated uppercase-pn"

# enable thumb for broader test coverage (oe-core autobuilder doesn't have thumb enabled)
PREFERRED_ARM_INSTRUCTION_SET              ?= "thumb"
ARM_INSTRUCTION_SET = "${PREFERRED_ARM_INSTRUCTION_SET}"

# use musl for qemux86 and qemux86copy
TCLIBC_qemux86 = "musl"
TCLIBC_qemux86copy = "musl"

