# $FreeBSD$

SYSDIR?=/usr/src/sys

.if ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386" || ${MACHINE_CPUARCH} == "aarch64" || ${MACHINE_ARCH} == "powerpc64"

SUBDIR=	linuxkpi	\
	ttm		\
	drm		\
	${_dummygfx}	\
	${_vboxvideo}	\
	${_vmwgfx}	\
	${_i915}	\
	amd		\
	radeon

.if ${MACHINE_CPUARCH} == "amd64" || ${MACHINE_CPUARCH} == "i386"
_i915 =		i915 
_vmwgfx =	vmwgfx
_vboxvideo =	vboxvideo
.endif

.if defined(DUMMYGFX)
_dummygfx = dummygfx
.endif

.include <bsd.subdir.mk>

.else
dummy:
	echo "Unsupported architecture"
.endif
