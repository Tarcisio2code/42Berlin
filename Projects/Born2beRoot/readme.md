# 42 Berlin - Projects - Born2beRoot

## Introduction

Born2beRoot is a project designed to introduce you to virtualization and basic system administration. The goal is to create a virtual machine using **VirtualBox** (or **UTM**, if VirtualBox is not available) under strict configuration rules. By the end of this project, you'll have successfully set up and configured a secure operating system following industry-standard practices.

## Table of Contents

- [Project Overview](#project-overview)
- [Virtual Machine Setup](#virtual-machine-setup)
- [Mandatory Requirements](#mandatory-requirements)
  - [Operating System](#operating-system)
  - [Encrypted Partitions](#encrypted-partitions)
  - [SSH and Firewall Configuration](#ssh-and-firewall-configuration)
  - [Password Policy](#password-policy)
  - [Sudo Configuration](#sudo-configuration)
- [Monitoring Script](#monitoring-script)
- [Key Learnings](#key-learnings)
- [References](#references)

## Project Overview

The project is focused on building a secure server environment with virtualization, proper system management, and strong security protocols. You will:
- Install and configure an operating system (Debian or CentOS) in a virtual machine.
- Implement strong security measures like encrypted partitions, firewalls, SSH restrictions, and a solid password policy.
- Develop a simple monitoring script to display system information periodically.

At the end, you'll understand fundamental system administration tasks and security best practices.

## Virtual Machine Setup

To begin, you'll need to create a virtual machine using **VirtualBox** (or **UTM** if VirtualBox is unavailable). You will install either:
- **Debian (Recommended)**: Latest stable version, ideal for beginners.
- **CentOS**: More complex but necessary to understand different system administration techniques (without KDump but with SELinux).

## Mandatory Requirements

### Operating System

- Install the **latest stable version** of either Debian or CentOS.  
- No graphical interface is allowed (no X.org or any similar software). The system must operate purely through the command line interface.

### Encrypted Partitions

You must configure at least **two encrypted partitions** using **LVM** (Logical Volume Manager). These partitions will ensure data security by encrypting stored information.

### SSH and Firewall Configuration

- The **SSH service** must be running on port **4242** only.
- Root login through SSH is forbidden for security reasons.
- Configure the **UFW firewall** to block all ports except **port 4242**. The firewall must be active when the virtual machine starts.
- If using CentOS, replace the default firewall with **UFW** (which may require installing DNF).

### Password Policy

You are required to enforce a **strong password policy** that complies with the following:
- Passwords expire every **30 days**.
- A **minimum of 2 days** is required between password changes.
- Users receive a **7-day warning** before their password expires.
- Passwords must:
  - Be at least **10 characters** long.
  - Contain at least **one uppercase letter** and **one number**.
  - Have **no more than 3 consecutive identical characters**.
  - Not contain the **user's name**.
  - Have **7 new characters** different from the previous password.
  
All passwords on the system, including the root password, must comply with this policy.

### Sudo Configuration

- Limit **sudo** authentication attempts to **3**. After 3 failed attempts, further access will be denied.
- Display a **custom error message** if an incorrect password is entered.
- All **sudo commands** must be logged in `/var/log/sudo/`.
- Enable **TTY mode** for sudo, and restrict the paths that can be used by sudo to:

