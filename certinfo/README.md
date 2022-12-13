# Certinfo

Use `libcurl` in a C extension in Python.

* [docs/examples/certinfo.c](https://github.com/curl/curl/blob/fd1ce3d4b085e7982975f29904faebf398f66ecd/docs/examples/certinfo.c)

```
$ make build
$ ldd build/lib.linux-x86_64-3.8/certinfo.cpython-38-x86_64-linux-gnu.so
        linux-vdso.so.1 (0x00007ffd82ff4000)
        libcurl.so.4 => /lib/x86_64-linux-gnu/libcurl.so.4 (0x00007f7778341000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x00007f7778119000)
        libnghttp2.so.14 => /lib/x86_64-linux-gnu/libnghttp2.so.14 (0x00007f77780ef000)
        libidn2.so.0 => /lib/x86_64-linux-gnu/libidn2.so.0 (0x00007f77780ce000)
        librtmp.so.1 => /lib/x86_64-linux-gnu/librtmp.so.1 (0x00007f77780af000)
        libssh.so.4 => /lib/x86_64-linux-gnu/libssh.so.4 (0x00007f7778040000)
        libpsl.so.5 => /lib/x86_64-linux-gnu/libpsl.so.5 (0x00007f777802c000)
        libssl.so.3 => /lib/x86_64-linux-gnu/libssl.so.3 (0x00007f7777f88000)
        libcrypto.so.3 => /lib/x86_64-linux-gnu/libcrypto.so.3 (0x00007f7777b46000)
        libgssapi_krb5.so.2 => /lib/x86_64-linux-gnu/libgssapi_krb5.so.2 (0x00007f7777af2000)
        libldap-2.5.so.0 => /lib/x86_64-linux-gnu/libldap-2.5.so.0 (0x00007f7777a93000)
        liblber-2.5.so.0 => /lib/x86_64-linux-gnu/liblber-2.5.so.0 (0x00007f7777a80000)
        libzstd.so.1 => /lib/x86_64-linux-gnu/libzstd.so.1 (0x00007f77779b1000)
        libbrotlidec.so.1 => /lib/x86_64-linux-gnu/libbrotlidec.so.1 (0x00007f77779a3000)
        libz.so.1 => /lib/x86_64-linux-gnu/libz.so.1 (0x00007f7777987000)
        /lib64/ld-linux-x86-64.so.2 (0x00007f7778401000)
        libunistring.so.2 => /lib/x86_64-linux-gnu/libunistring.so.2 (0x00007f77777dd000)
        libgnutls.so.30 => /lib/x86_64-linux-gnu/libgnutls.so.30 (0x00007f77775f0000)
        libhogweed.so.6 => /lib/x86_64-linux-gnu/libhogweed.so.6 (0x00007f77775a8000)
        libnettle.so.8 => /lib/x86_64-linux-gnu/libnettle.so.8 (0x00007f7777562000)
        libgmp.so.10 => /lib/x86_64-linux-gnu/libgmp.so.10 (0x00007f77774e0000)
        libkrb5.so.3 => /lib/x86_64-linux-gnu/libkrb5.so.3 (0x00007f7777415000)
        libk5crypto.so.3 => /lib/x86_64-linux-gnu/libk5crypto.so.3 (0x00007f77773e6000)
        libcom_err.so.2 => /lib/x86_64-linux-gnu/libcom_err.so.2 (0x00007f77773de000)
        libkrb5support.so.0 => /lib/x86_64-linux-gnu/libkrb5support.so.0 (0x00007f77773d0000)
        libsasl2.so.2 => /lib/x86_64-linux-gnu/libsasl2.so.2 (0x00007f77773b5000)
        libbrotlicommon.so.1 => /lib/x86_64-linux-gnu/libbrotlicommon.so.1 (0x00007f7777392000)
        libp11-kit.so.0 => /lib/x86_64-linux-gnu/libp11-kit.so.0 (0x00007f7777257000)
        libtasn1.so.6 => /lib/x86_64-linux-gnu/libtasn1.so.6 (0x00007f777723d000)
        libkeyutils.so.1 => /lib/x86_64-linux-gnu/libkeyutils.so.1 (0x00007f7777236000)
        libresolv.so.2 => /lib/x86_64-linux-gnu/libresolv.so.2 (0x00007f7777222000)
        libffi.so.8 => /lib/x86_64-linux-gnu/libffi.so.8 (0x00007f7777215000)
```
