#!/bin/bash
export SSH_AUTH_SOCK=/run/user/1000/keyring/ssh
export GPG_AGENT_INFO=/run/user/1000/gnupg/S.gpg-agent:0:1
export DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus
export XAUTHORITY=/run/user/1000/gdm/Xauthority
export DISPLAY=:1
source ~/.bashrc
source ~/.profile