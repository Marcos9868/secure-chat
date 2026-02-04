# Secure Chat — Private P2P Communication System (C++)

## 📌 Overview

**Secure Chat** is a cross-platform, offline-first desktop application written in **C++**, designed to provide private and secure communication between users **without any form of surveillance, telemetry, or centralized data storage**.

The project is built around strong principles of **privacy, modern cryptography, decentralization, and full user control over data**.

---

## 🎯 Project Goals

* Enable private communication between users
* No email, password, or centralized account system
* No server-side data storage
* Conversation history is **local and disposable**
* Strong cryptography with minimal performance impact
* Simple, auditable, and extensible architecture

---

## 🔐 Security & Privacy Principles

The following principles are **non-negotiable**:

1. **Zero Telemetry**
   No data collection, analytics, remote logging, or tracking.

2. **Zero Trust in Servers**
   No centralized databases, user profiles, or persistent identities outside the user machine.

3. **Always-On Encryption**
   All communications are end-to-end encrypted.

4. **Message Signing**
   No message is valid unless cryptographically signed.

5. **User-Controlled Data**
   If local data is deleted, the conversation history is permanently lost.

---

## 🧑‍💻 User Identity Model

* Each user is identified exclusively by a **cryptographic key pair** (SSH-like model).
* Keys are:

  * Generated locally
  * Never transmitted to third parties
  * Never stored on servers

### Identity = Public Key

There is no:

* Username
* Email
* Password

The **public key is the user identity**.

---

## 🧩 Planned Features (MVP → Evolution)

### 🔹 MVP (Minimum Viable Product)

* [ ] Local cryptographic key pair generation
* [ ] Authentication via key ownership
* [ ] P2P text messaging
* [ ] End-to-end encryption
* [ ] Message signing and verification
* [ ] Local conversation history

### 🔹 Post-MVP Features

* [ ] Image sharing (JPG / PNG)
* [ ] Private rooms
* [ ] Minimalist graphical interface
* [ ] UX improvements
* [ ] Full portability (Linux / Windows / macOS)

---

## 🧠 High-Level Architecture

### Communication Model

```
User A  <----->  User B
 (key)             (key)
```

* Direct peer-to-peer communication whenever possible
* No trusted intermediaries

---

## 🗂 Initial Project Structure

```
secure-chat/
├── CMakeLists.txt
├── README.md
├── src/
│   ├── core/
│   │   ├── crypto/
│   │   ├── identity/
│   │   └── messaging/
│   ├── net/
│   └── storage/
├── tests/
└── docs/
```

---

## 🛠 Technologies

* **Language:** C++ (C++20)
* **Build System:** CMake + Ninja
* **Cryptography:** libsodium
* **Networking:** sockets (initially TCP/UDP)
* **UI (future):** Qt or Dear ImGui (TBD)

---

## 📜 Data Storage Model

* All data is stored **locally only**
* No sensitive data is committed to the repository
* Suggested local directories:

```
~/.secure-chat/
├── identity/
├── conversations/
└── cache/
```

If this directory is deleted:

> ❗ All conversation history is permanently lost

---

## 🧪 Testing Strategy

* Unit tests per module
* P2P integration tests
* No real user data in tests

---

## 🧭 Development Roadmap

1. Base project structure
2. Cryptography module
3. Secure identity generation and persistence
4. Message signing and verification
5. Basic P2P communication
6. Local conversation persistence
7. Minimal UI for testing

---

## 🤝 Contributions

This project prioritizes:

* Clean and readable code
* Security over convenience
* Architectural simplicity
* Auditability

All contributions must respect these principles.

---

## ⚠️ Disclaimer

This software is provided **"as is"**, without warranties of any kind. Use at your own risk.

---

## ✨ Motivation

Secure Chat exists to:

> **Give people back control over their communications.**

No surveillance. No tracking. No dependency.

## Start commands

```bash
cmake -S . -B build -G Ninja
ninja -C build
```