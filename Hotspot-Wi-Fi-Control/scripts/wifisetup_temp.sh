#!/bin/bash


cat > /etc/rc.local <<EOF
#!/bin/sh -e
exit 0
EOF

cat > /etc/network/interfaces <<EOF
auto lo
iface lo inet loopback
iface eth0 inet manual
allow-hotplug wlan0
iface wlan0 inet dhcp
wpa-conf /etc/wpa_supplicant/wpa_supplicant.conf
EOF

cat > /etc/wpa_supplicant/wpa_supplicant.conf <<EOF
ctrl_interface=DIR=/var/run/wpa_supplicant GROUP=netdev
update_config=1
country=US
network={
ssid="PLDTHOMEFIBR36684"
scan_ssid=1
psk="doNotConnect01;"
}
EOF

echo "Wifi All done! - reboot now"
