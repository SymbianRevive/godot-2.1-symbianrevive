#!/usr/bin/env bash
elf2e32 \
  --capability="LocalServices+ReadUserData+UserEnvironment+WriteUserData+NetworkServices" \
  --elfinput="${1:?input required}" --output="${2:?output required}.exe" --libpath="${3:?libroot required}" --linkas="${2:?output required}" \
  --fpu=softvfp --uid1=0x1000007a --uid2=0x100039ce --uid3="${4:-A0060D07}" --sid="${4:-A0060D07}" --targettype=EXE \
  --dlldata --ignorenoncallable --smpsafe --heap=0x800000,0x3000000 --stack=0x10000
