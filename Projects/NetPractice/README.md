# 📡 NetPractice

> Networking fundamentals through hands-on IPv4 addressing, subnetting and routing exercises.

## 📖 About

NetPractice is a networking project from the 42 curriculum designed to teach the foundations of computer networks through a series of practical exercises.

Unlike traditional programming projects, NetPractice focuses on understanding how devices communicate across networks, how routers forward packets, and how subnetting affects network design.

The project consists of 10 progressively challenging levels where incomplete network configurations must be analyzed and corrected to restore connectivity between hosts.

Throughout the project, I learned how IP addressing, subnet masks, gateways, and routing tables work together to enable communication across multiple networks.

---

# 🎯 Project Objectives

The main goals of NetPractice are:

* Understand IPv4 addressing.
* Learn how subnet masks divide networks.
* Configure hosts within the same subnet.
* Understand network boundaries.
* Configure default gateways.
* Learn how routers forward packets.
* Understand static routing.
* Build and troubleshoot multi-router topologies.
* Develop a systematic approach to network debugging.

---

# 🧠 Concepts Learned

## 🌐 IPv4 Addressing

An IPv4 address uniquely identifies a device on a network.

Example:

```text
192.168.1.42
```

Each address contains:

* A Network Portion
* A Host Portion

The subnet mask determines where the separation occurs.

---

## 🎭 Subnet Masks

Subnet masks define which bits belong to the network and which belong to hosts.

Examples:

```text
255.255.255.0   = /24
255.255.255.128 = /25
255.255.255.192 = /26
255.255.255.240 = /28
```

Subnetting allows a larger network to be divided into smaller logical networks.

Example:

```text
192.168.1.0/24

becomes

192.168.1.0/25
192.168.1.128/25
```

---

## 🏠 Local Networks

Devices can communicate directly only when they belong to the same network.

Example:

```text
Host A: 192.168.1.10/24
Host B: 192.168.1.20/24
```

Both hosts belong to:

```text
192.168.1.0/24
```

and can communicate without a router.

---

## 🚦 Default Gateway

When a host needs to communicate with a device outside its local network, it sends packets to its default gateway.

```text
Host
  │
  ▼
Gateway
  │
  ▼
Remote Network
```

The gateway is typically a router interface located within the same subnet as the host.

---

## 🔀 Routing

Routers connect different networks.

When a packet arrives, the router:

1. Examines the destination IP.
2. Searches its routing table.
3. Selects the best route.
4. Forwards the packet to the next hop.

```text
Packet
  │
  ▼
Router
  │
Routing Table Lookup
  │
  ▼
Next Hop
```

---

## 🌍 Default Route

A default route is used when no more specific route exists.

Notation:

```text
0.0.0.0/0
```

Meaning:

```text
"Any destination network"
```

This concept is fundamental for Internet connectivity.

---

# 📚 Skills Acquired

## Network Analysis

* Identifying network boundaries.
* Determining network and broadcast addresses.
* Calculating valid host ranges.
* Detecting incorrect configurations.

## Subnetting

* CIDR notation.
* Host capacity calculations.
* Network segmentation.
* Address planning.

## Routing

* Static routes.
* Default routes.
* Multi-hop communication.
* Router interface configuration.

## Troubleshooting

* Reading incomplete network topologies.
* Finding addressing inconsistencies.
* Verifying route correctness.
* Isolating connectivity issues.

---

# 🗂️ Repository Structure

```text
NetPractice/
├── README.md
├── user_doc.md
├── solutions.md
└── configs/
```

### README.md

Project overview, networking concepts and lessons learned.

### user_doc.md

Personal networking reference guide containing:

* IPv4 fundamentals
* Subnetting cheat sheets
* Routing concepts
* Troubleshooting methodology

### solutions.md

Walkthrough of all NetPractice levels, including:

* Objectives
* Network diagrams
* Solution summaries
* Concepts learned

---

# 📈 Learning Progression

| Level | Main Topic             |
| ----- | ---------------------- |
| 1     | Basic IP addressing    |
| 2     | Network membership     |
| 3     | Subnet masks           |
| 4     | Router interfaces      |
| 5     | Default gateways       |
| 6     | Router to Internet     |
| 7     | Multiple routers       |
| 8     | Static routing         |
| 9     | Advanced routing       |
| 10    | Full topology analysis |

Each level builds upon the previous one, gradually introducing more complex networking concepts.

---

# 🎓 Key Takeaways

NetPractice transformed networking concepts that initially seemed abstract into practical and intuitive knowledge.

The project provided hands-on experience with:

* IPv4 addressing
* Subnetting
* Routing
* Gateways
* Packet forwarding
* Network troubleshooting

Understanding these concepts is essential not only for system administration and networking roles, but also for software engineers working with distributed systems, cloud infrastructure, containers, and modern web applications.

---

# ✅ Conclusion

NetPractice serves as an excellent introduction to computer networking.

By progressively solving increasingly complex topologies, I developed a solid understanding of how packets move across networks, how routers make forwarding decisions, and how subnetting influences network design.

The knowledge acquired in this project provides a strong foundation for future studies in:

* System Administration
* DevOps
* Cloud Computing
* Network Engineering
* Cybersecurity
* Distributed Systems
* Containerized Infrastructure
