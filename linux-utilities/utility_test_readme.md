## Testing commands for Linux utilities with Ratel

We tested a number of Linux utilities with Ratel. Here we provide the specifics of the input configurations for each utility for your tests (if any). Note that some utilities require configuring your own test directory and creating the related test files that are easy to make or download from online, we hence don't contain them in this repo. Besides, for some utilities that have lots of input arguments, we just test them by quickly changing arguments from one to another to save time. So users may use other arguments on a given utility for your tests except the listed below.


## Commands as follows:

```bash
./ratel -- ./grep -irn "build" Makefile.test
./ratel -- ./ed
sudo ./ratel -- ./fusermount -u /media/sgx16/0a3b1d97-b2de-4b8a-bb94-733d3611c8b8
./ratel -- ./hciconfig -a hci0, ... see more cmds in issues.txt
./ratel -- ./journalctl
./ratel -- ./kmod list and ./ratel -- ./kmod static-nodes
./ratel -- ./lessecho jhcui
./ratel -- ./lesskey -o lesskey-r.out lesskey.txt
./ratel -- ./loginctl
./ratel -- ./networkctl
./ratel -- ./systemctl
./ratel -- ./systemd-ask-password
./ratel -- ./systemd-escape -u jhcui
./ratel -- ./systemd-hwdb query MODALIAS and sudo ./ratel -- ./systemd-hwdb update
./ratel -- ./systemd-inhibit --list and ./ratel -- ./systemd-inhibit --why=jhcui
./ratel -- ./systemd-machine-id-setup and ./ratel -- ./systemd-machine-id-setup --root=ROOT
./ratel -- ./systemd-notify --status=TEXT
./ratel -- ./systemd-tmpfiles --clean
./ratel -- ./systemd-tty-ask-password-agent
./ratel -- ./udevadm test-builtin net_id ./ and ./ratel -- ./udevadm test-builtin net_id control/monitor/test
./ratel -- ./ulockmgr_server
./ratel -- ./bccmd enabletx
./ratel -- ./bluemoon and ./ratel -- bluemoon -C ipw2200-ibss.fw 
sudo ./bootctl status and sudo ./ratel -- ./bootctl status
./ratel -- ./brltty-ctb -r Makefile.test and ./ratel -- ./brltty-ctb -c af.ctb
./ratel -- ./brltty-trtxt -6 Makefile.test and ./ratel -- ./brltty-trtxt -i ar.ttb Makefile.test and ./ratel -- ./brltty-trtxt -o ar.ttb Makefile.test
./ratel -- ./btattach -A 1C:52:16:85:24:DE
./ratel -- ./btmgmt con and sudo ./ratel -- ./btmgmt le on
sudo ./ratel -- ./btmon -t and sudo ./ratel -- ./btmon -S
./ratel -- ./busctl
./ratel -- ./catman -d
./ratel -- ./cd-it8 create-sp OUTPUT.sp FL_insurance_sample.csv norm
sudo ./ratel -- ./chage -l sgx16 and sudo ./ratel -- ./chage -m 7989 sgx16
./ratel -- ./ciptool search
./ratel ./cupstestdsc -
./ratel -- ./cupstestppd jhcui.ppd
./ratel -- ./curl -v 74.125.24.101 and ./ratel -- ./curl https://www.linux.com
./ratel -- ./cvt 1600 1200 60
./ratel -- ./dbus-cleanup-sockets and ./ratel -- ./dbus-cleanup-sockets --version
./ratel -- ./dbus-monitor
./ratel -- ./dbus-send --dest=org.freedesktop.ExampleName /org/freedesktop/sample/object/name org.freedesktop.ExampleInterface.ExampleMethod int32:47 string:'hello world' double:65.32
./ratel -- ./dbus-update-activation-environment --systemd --all
./ratel -- ./dbus-uuidgen
./ratel -- ./derb -t 1024
./ratel -- ./dirmngr
./ratel -- ./dirmngr-client --lookup 127.0.0.1 and ./ratel -- ./dirmngr-client --url 127.0.0.1
./ratel -- ./enchant -l Makefile.test 
./ratel -- ./enchant-lsmod -list-dicts
./ratel -- ./epsffit 0 0 100 100 epsf.eps ps-out2.eps
./ratel -- ./eqn Makefile.test 
./ratel -- ./evince-thumbnailer -s 100 file_example_TIFF_1MB.tiff file-out2.tiff
./ratel -- ./expiry -c and ./ratel -- ./expiry -f
./ratel -- ./faillog -a
./ratel -- ./fcitx-dbus-watcher
./ratel -- ./fcitx-remote -a  and ./ratel -- ./fcitx-remote -o
./ratel -- ./find ./ -name jhcui1
./ratel -- ./fwupdate -s
./ratel -- ./gamma4scanimage 3
./ratel -- ./gatttool -b C8:0F:10:1B:CE:5E -I
./ratel -- ./gawk '{print $1}' test1.csv
./ratel -- ./genbrk -r KeywordTokenizer.rbbi -o genbrk2.out
./ratel -- ./gencfu -r KeywordTokenizer.rbbi -w genbrk.out -o gencfu.txt
./ratel -- ./gencnval ./data/mappings/convrtrs.txt
./ratel -- ./gendict words.txt --uchars dict2.out
./ratel -- ./genrb genrb-test.res
./ratel -- ./gpg2 --encrypt --recipient jhcui.gid@gmail.com Makefile.test
./ratel -- ./gpg-agent --allow-preset-passphrase
./ratel -- ./gpg-connect-agent --dirmngr
./ratel -- ./gpgparsemail --crypto test1.csv
./ratel -- ./grops -glmv -P/usr/share/groff/1.22.4/oldfont
./ratel -- ./grotty -bBcdfhioruUv -P/usr/share/groff/1.22.4/oldfont
./ratel -- ./gtf x y refresh
./ratel -- ./hciattach -l
./ratel -- ./hcitool dev and ./ratel -- ./hcitool inq and ./ratel -- ./hcitool scan
./ratel -- ./hex2hcd as102_data1_st.hex -o as102-02.hcd
./ratel -- ./hostnamectl
./ratel -- ./htop
./ratel -- ./icuinfo
./ratel -- ./kbxutil --stats sforshee.hex
./ratel -- ./kerneloops-submit --file /var/log/kern.log
sudo ./ratel --  ./l2ping 5C:66:6C:6C:A9:6E
./ratel -- ./l2test -r
./ratel -- ./lastlog -b 2
./ratel -- lexgrog -c whatis.cat1 -d
./ratel -- ./localectl status
./ratel -- ./makeconv gb-18030-2000.ucm
./ratel -- ./mandb -d
./ratel -- ./manpath -d -c
./ratel -- ./obexctl
./ratel -- ./pg_config
./ratel -- ./pic Makefile.test
./ratel -- ./pkgdata  -p files  data/in/uprops.icu
./ratel -- ./ppdc ppdi.drv
./ratel -- ./ppdhtml ppdi.drv
./ratel -- ./ppdi jhcui.ppd
./ratel -- ./ppdmerge jhcui.ppd
./ratel -- ./ppdpo -o ppdi.po  ppdi.drv
./ratel -- ./preconv Makefile.test
./ratel -- ./psbook -q Makefile.test
./ratel -- ./psnup Makefile.test and ./ratel -- ./psnup -q -w2 -h2 -l -r -c -f config-paper.ps out2.ps
./ratel -- ./psresize -PA4 -pletter in.ps out.ps
./ratel -- ./psselect -p 1 viewgif.ps  viewgif2.out
./ratel -- ./pstops -pa4 4:1L@0.7\(1w,0\)+2L@0.7\(1w,0.5h\),0R@0.7\(0,1h\)+3R@0.7\(0,0.5h\) viewgif.ps  viewgif3.out
./ratel -- ./qpdf paper.pdf paper2.out
./ratel -- ./rctest
./ratel -- ./rfcomm -i hci0
./ratel -- ./sdptool records F0:79:E8:2A:6B:54 and ./ratel -- ./sdptool get --bdaddr F4:06:16:21:AA:27 SAP
./ratel -- ./soelim
./ratel -- ./ssh-add -k
./ratel -- ./ssh-keyscan -f hostlist.txt and ./ratel -- ./ssh-keyscan -t rsa,dsa,ecdsa,ed25519 -f known_hosts | sort -u - ssh_known_hosts | diff ssh_known_hosts -
sudo ./ratel -- ./sudoreplay -l
./ratel -- ./systemd-analyze plot
./ratel -- ./systemd-cgtop -k
./ratel -- ./systemd-detect-virt -v
./ratel -- ./systemd-path
./ratel -- ./systemd-resolve --statistics
sudo ./ratel -- systemd-run env
./ratel -- ./systemd-stdio-bridge --address=5C:66:6C:6C:A9:6E
./ratel -- ./t1ascii jhcui.pfb > jhcui-new2.pfa
./ratel -- ./t1asm OpenSans-Regular.raw > jhcui.pfb and ./ratel -- ./t1asm -a OpenSans-Regular.raw > jhcui.pfa
./ratel -- ./t1binary -l 20 jhcui-new2.pfa -o jhcui-new.pfb
./ratel -- ./t1disasm OpenSans-Regular.pfb OpenSans-Regular.raw
./ratel -- ./t1mac --binhex OpenSans-Regular.pfb -o t1mac.test and ./ratel -- ./t1mac --appledouble OpenSans-Regular.pfb -o t1mac.test
./ratel -- ./t1unmac t1mac.test > t1unmac.test
 ./ratel -- ./tbl and ./ratel -- ./tbl -C Makefile.test
./ratel -- ./timedatectl list-timezones and ./ratel -- ./timedatectl --adjust-system-clock and ./ratel -- ./timedatectl set-local-rtc false
./ratel -- ./transfig Makefile.test
./ratel -- ./troff Makefile.test
./ratel -- ./uconv -f ibm-1160 background.mp4 -o background-new2.mp4 and ./ratel -- ./uconv -f utf-8 -c Makefile >/dev/null
./ratel -- ./vim.basic jhcui.txt
./ratel -- ./vim.tiny
sudo ./ratel -- ./volname /dev/console
./ratel -- ./watchgnupg --verbose --force ~/.gnupg/S.log
./ratel -- ./webapp-container-hook
./ratel -- ./wget http://183.232.231.174 and ./ratel -- wget http://www.baidu.com
./ratel -- ./whatis -vrwl fstat
./ratel -- ./wpa_passphrase jhcui
./ratel -- ./xmlcatalog --shell and ./ratel -- ./xmlcatalog --create
./ratel -- ./xmllint xml-test.xml --html
./ratel -- ./xxd -s -0x30 Makefile.test
./ratel -- ./zlib-flate -compress < jhcui.raw > jhcui.comp and ./ratel -- ./zlib-flate -uncompress < jhcui.comp > jhcui.uncomp
```

