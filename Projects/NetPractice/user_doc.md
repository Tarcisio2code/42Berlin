# 📚 NetPractice - User Documentation

> Personal networking cheat sheet created during the 42 NetPractice project.

---

# 🌐 IPv4 Fundamentals

An IPv4 address uniquely identifies a device on a network.

Example:

```text
192.168.1.42
```

IPv4 addresses contain 32 bits divided into 4 octets.

```text
192 . 168 . 1 . 42
 8      8    8    8 bits
```

An IP address is composed of:

```text
[ Network Portion ][ Host Portion ]
```

The subnet mask determines where the separation occurs.

---

# 🎭 Subnet Masks

Subnet masks identify which bits belong to the network.

Common masks:

| CIDR | Subnet Mask     |
| ---- | --------------- |
| /8   | 255.0.0.0       |
| /16  | 255.255.0.0     |
| /24  | 255.255.255.0   |
| /25  | 255.255.255.128 |
| /26  | 255.255.255.192 |
| /27  | 255.255.255.224 |
| /28  | 255.255.255.240 |
| /29  | 255.255.255.248 |
| /30  | 255.255.255.252 |

---

# 🔢 CIDR Quick Reference

CIDR notation indicates how many bits belong to the network.

Example:

```text
192.168.1.10/24
```

means:

```text
Network Bits : 24
Host Bits    : 8
```

---

## Useful Values

| CIDR | Hosts |
| ---- | ----- |
| /24  | 254   |
| /25  | 126   |
| /26  | 62    |
| /27  | 30    |
| /28  | 14    |
| /29  | 6     |
| /30  | 2     |

Formula:

```text
Hosts = 2^(Host Bits) - 2
```

The subtraction accounts for:

* Network Address
* Broadcast Address

---

# 🏠 Network Address

The network address identifies the subnet itself.

Example:

```text
IP   : 192.168.1.42
Mask : /24

Network:
192.168.1.0
```

---

# 📢 Broadcast Address

The broadcast address reaches every device inside a subnet.

Example:

```text
Network:
192.168.1.0/24

Broadcast:
192.168.1.255
```

---

# 👥 Valid Host Range

Example:

```text
192.168.1.0/24
```

| Type       | Address       |
| ---------- | ------------- |
| Network    | 192.168.1.0   |
| First Host | 192.168.1.1   |
| Last Host  | 192.168.1.254 |
| Broadcast  | 192.168.1.255 |

---

# ✂️ Subnetting

Subnetting divides a larger network into smaller networks.

Example:

```text
192.168.1.0/24
```

Split into:

```text
192.168.1.0/25
192.168.1.128/25
```

Result:

```text
2 subnets
126 hosts each
```

---

# 🚦 Default Gateway

A gateway is the router interface used to reach other networks.

```text
Host
 │
 ▼
Gateway
 │
 ▼
Destination
```

Rule:

> The gateway must belong to the same subnet as the host.

Example:

```text
Host:
192.168.1.10/24

Gateway:
192.168.1.1
```

Valid ✅

---

# 🔀 Routers

Routers connect different networks.

Example:

```text
192.168.1.0/24
        │
        ▼
     Router
        │
        ▼
10.0.0.0/24
```

Each router interface belongs to a different network.

Example:

```text
R1 = 192.168.1.1
R2 = 10.0.0.1
```

---

# 🗺️ Routing Tables

Routers decide where to forward packets using routing tables.

Example:

```text
Destination      Next Hop
--------------------------------
10.0.0.0/24      Direct
172.16.0.0/24    10.0.0.2
```

Packet flow:

```text
Packet
  │
  ▼
Routing Table Lookup
  │
  ▼
Next Hop
```

---

# 🌍 Default Route

Default route:

```text
0.0.0.0/0
```

Meaning:

```text
Any unknown destination
```

Example:

```text
0.0.0.0/0 -> 192.168.1.1
```

If no more specific route exists:

```text
Send packet to 192.168.1.1
```

---

# 📨 Packet Journey

Example:

```text
Host A:
192.168.1.10

Host B:
10.0.0.20
```

```text
Host A
   │
   ▼
Gateway
   │
   ▼
Router
   │
   ▼
Router
   │
   ▼
Host B
```

Each router repeats:

```text
Check destination IP
Find route
Forward packet
```

---

# 🔎 Troubleshooting Methodology

Whenever a level fails:

## Step 1

Check IP addresses.

```text
Are they valid?
```

---

## Step 2

Check subnet masks.

```text
Same subnet?
```

---

## Step 3

Calculate network addresses.

```text
Do both devices belong to the same network?
```

---

## Step 4

Check gateways.

```text
Does the host know where to send external traffic?
```

---

## Step 5

Check router interfaces.

```text
Does each interface belong to the correct subnet?
```

---

## Step 6

Check routing tables.

```text
Does a route exist for the destination network?
```

---

# 🎯 NetPractice Evaluation Strategy

For every exercise:

### Identify all networks

```text
Network A
Network B
Network C
```

---

### Identify routers

```text
Which networks does each router connect?
```

---

### Verify hosts

```text
IP
Mask
Gateway
```

---

### Verify routes

```text
Destination
Next Hop
```

---

### Test packet flow mentally

```text
Host
 ↓
Gateway
 ↓
Router
 ↓
Destination
```

If you cannot describe the path, the configuration is likely incorrect.

---

# ⚠️ Common Mistakes

## Wrong Gateway

```text
Host:
192.168.1.10

Gateway:
10.0.0.1
```

Invalid ❌

Gateway must be inside the same subnet.

---

## Wrong Subnet Mask

```text
Host A:
192.168.1.10/24

Host B:
192.168.1.20/25
```

Potentially invalid ❌

Always verify network ranges.

---

## Missing Default Route

```text
Host knows local network only.
```

Cannot reach external networks.

---

## Router Interface Outside Subnet

```text
Host:
192.168.1.10/24

Router:
10.0.0.1/24
```

Invalid ❌

---

# 🏆 Key Lessons Learned

Through NetPractice I learned:

* IPv4 addressing
* Network boundaries
* Subnetting
* CIDR notation
* Gateways
* Routing
* Static routes
* Packet forwarding
* Network troubleshooting

These concepts form the foundation of:

* DevOps
* System Administration
* Cloud Computing
* Cybersecurity
* Network Engineering
* Containerized Infrastructure
