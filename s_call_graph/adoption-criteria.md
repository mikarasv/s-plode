# Selection Process for the CallGraph Tool

This document outlines the methodology and criteria used to select the tool for generating s-graphs within s-plode.
A comparative analysis of different tools considered for the creation, modification, and analysis of graphs will be carried out.

# Tools considered

The tools considered were:

- **[networkX](https://github.com/networkx/networkx)**: a Python library for the creation, manipulation, and analysis of graphs and complex networks. It provides tools for working with directed and undirected graphs, performing structural analysis, applying classical algorithms, and visualizing networks, all within a flexible and easy-to-use environment.

- **[rustworkx](https://github.com/Qiskit/rustworkx)**: a general-purpose, high-performance graph library for Python, written in Rust to provide efficiency and speed in complex graph operations. It is especially useful in contexts where performance is critical, such as optimization or large-scale analysis.

- **[graph-tool](https://git.skewed.de/count0/graph-tool)**: an efficient Python module for the manipulation and statistical analysis of graphs. Since its data structures and algorithms are implemented in C++, it achieves strong performance in terms of memory usage and speed.

- **[pygraph](https://github.com/jciskey/pygraph)**: a graph manipulation library written entirely in pure Python, without depending on external libraries beyond Python’s standard library. This simplifies its installation and basic use.

- **[neo4j](https://neo4j.com/)**: a high-performance graph database designed to store, query, and manage highly connected data. It combines the robustness and features of a mature database with the flexibility of a graph-oriented model, making it ideal for efficiently representing complex relationships.

---

# Evaluation Criteria

Four evaluation criteria were established with different weights to determine the score of each tool. Based on these criteria, the result for each tool was calculated using a weighted average. The evaluation criteria and their respective weights (in parentheses) are as follows:

- **Functionality (1)**: Evaluates whether the tool covers the core needs of the project, which in this case is the creation of a graph with nodes and edges that have certain attributes. If it does not meet the minimum required functionality, no points are awarded. Otherwise, 1 point is given.

- **Google Scorecard (2)**: Used to evaluate the security aspects of the tool, including dependency management, vulnerability mitigation, and code supply chain integrity. Security is important for ensuring the reliability of the development environment, though it is not the main factor in this case.

- **Ease of Use (3)**: This criterion is evaluated based on two aspects:
  - **Installation and functionality (1)**: if the tool is easy to install, it receives 1 point; otherwise, 0 points.
  - **Documentation quality (2)**: the existence and quality of documentation is assessed. If it is insufficient or non-existent, 0 points are given. If it is basic or partially outdated, 1 point. If it is clear, complete, and well-maintained, 2 points.

  A tool with low usability can slow down development, increase the learning curve, and negatively impact productivity as well as future iterations of **S-plode**.

- **Performance (4)**: Evaluates the tool’s ability to handle large datasets, focusing primarily on speed. Performance is relevant in this context because **S-plode** requires processing potentially large graphs and executing costly algorithms.

  To evaluate this, a file with more than **30,000 lines** from the **EDK II project** was used. EDK II is an open-source implementation of the development environment for firmware for the **UEFI (Unified Extensible Firmware Interface)** and UEFI platform initialization.

  Using this file, a graph with approximately **120,000 nodes and 175,000 edges** was generated, and its performance was measured with the **cProfiler** tool. Full profiling results can be found in the `prolifing` folder.

  The total time was rounded to the nearest integer following standard rounding rules. The scoring was defined as:
  - Between 0 and 1 second → optimal (maximum score: 4 points).
  - Between 2 and 5 seconds → 3 points.
  - Between 6 and 10 seconds → 2 points.
  - More than 10 seconds → 1 point.

---


# Analysis

Based on the obtained results, the score of each tool was determined using the following procedure:

1. Scores were normalized for each criterion by dividing them by their maximum possible score.
2. The normalized results were multiplied by the weight assigned to each criterion.
3. All weighted values were summed.
4. The total sum was divided by the total weight sum (10) to obtain the final weighted average.

The table below presents the scores obtained for each tool.

| Library | Functionality (1) | Google Scorecard (2) | Ease of Use (3) | Performance (4) | Sum of weighted values | Final Score |
|---------|-------------------|----------------------|-----------------|-----------------|------------------------|-------------|
| **NetworkX** | 1 / 1 = 1 | 5.5 / 10 = 0.55 | 3 / 3 = 1.0 | 3 / 4 = 0.75 | 1 * 1 + 0.55 * 2 + 1 * 3 + 0.75 * 4  | **8.10 / 10** |
| **Rustworkx**| 1 / 1 = 1 |  6.4 / 10 = 0.64 | 3 / 3 = 1.0 | 4 / 4 = 1.0 | 1 * 1 + 0.64 * 2 + 1 * 3 + 1 * 4 | **9.28 / 10** |
| **Graph-Tool**| 1 / 1 = 1 |  3.9 / 10 = 0.39 | 2 / 3 = 0.66  | 2 / 4 = 0.5 | 1 * 1 + 0.39 * 2 + 0.66 * 3 + 0.5 * 4 | **5.78 / 10** |
| **PyGraph** | 0 / 1 = 0 |  2.6 / 10 = 0.26 | 1 / 3 = 0.33  | 4 / 4 = 1.0 | 0 * 1 + 0.26 * 2 + 0.33 * 3 + 1 * 4 | **5.52 / 10** |
| **Neo4j** | 1 / 1 = 1 | 6.1 / 10 = 0.61 | 2 / 3 = 0.66 | 1 / 4 = 0.25 | 1 * 1 + 0.61 * 2 + 0.66 * 3 + 0.25 * 4 | **5.22 / 10** |

The following sections will detail how these results were obtained.

---

## NetworkX

### Functionality
NetworkX provides all the necessary functionality for building and manipulating graphs in Python, including support for directed graphs and the ability to assign attributes to both nodes and edges.

### Scorecard
The scorecard result, as of 2025-01-06, using commit `17e0eaea449a18305e76d7a5227b4eb49f9cb11f`, was **5.5**.
The following table shows a more detailed analysis.


**Date:** 2025-01-06
**Commit:** `17e0eaea449a18305e76d7a5227b4eb49f9cb11f`
**Overall Score:** 5.5

| **Check Name**      | **Score** | **Reason**                                                 | **Details**                                                                          |
| ------------------- | --------- | ---------------------------------------------------------- | ------------------------------------------------------------------------------------ |
| Code-Review         | 10        | All changesets reviewed                                    | -                                                                                    |
| Maintained          | 10        | 30 commits and 14 issues in the last 90 days               | -                                                                                    |
| CII-Best-Practices  | 0         | No effort to earn an OpenSSF best practices badge detected | -                                                                                    |
| Dangerous-Workflow  | 0         | Dangerous workflow patterns detected                       | Warn: script injection detected in `.github/workflows/benchmark.yml:84`              |
| Token-Permissions   | 0         | GitHub workflow tokens with excessive permissions          | Multiple warnings regarding missing top-level permissions across `.github/workflows` |
| License             | 9         | License file detected, but not FSF or OSI-compliant        | Info: License file found at `LICENSE.txt`                                            |
| Binary-Artifacts    | 10        | No binaries found in the repo                              | -                                                                                    |
| Vulnerabilities     | 10        | No existing vulnerabilities detected                       | -                                                                                    |
| Signed-Releases     | -1        | No releases found                                          | -                                                                                    |
| Pinned-Dependencies | 0         | Dependency not pinned by hash detected                     | Multiple warnings regarding GitHub Actions not pinned in `.github/workflows/*`       |

### Ease of Use
Its documentation is constantly updated and clearly structured, including sections for installation, getting started, practical examples, and API references.
The learning curve is low: installation is straightforward and usage is intuitive, making the user experience smooth. It also provides several support channels, such as the official NetworkX repository (which includes a dedicated section for questions) and an official Google Group for discussions and inquiries.

### Performance
Its performance is reasonable for a library implemented in pure Python, with a total runtime of **1.875 seconds** and **3,118,744 function calls**. Most of the execution time is spent on node and edge insertion operations.
Although the simplicity and flexibility of NetworkX make it an excellent option, according to Memgraph’s documentation, it is not the most suitable tool when efficiency in very large ingestions is required:
> “Since NetworkX stores graph data in Python objects, it cannot handle tens of millions of objects without consuming large amounts of memory. This leads to out-of-memory errors when working with graphs of that size.” [5]

---

## RustworkX

### Functionality
RustworkX also provides all the functionality required for graph construction and manipulation, as it is inspired by NetworkX, with the difference that it is optimized for heavy workloads.

### Scorecard
The scorecard result, as of 2025-01-14, using commit `752555d2b22000784464db90187c3afba60f72b1`, was **6.4**.
The following table shows a more detailed analysis.

| **Check Name**         | **Score** | **Reason**                                                                       | **Details**                                                                |
| ---------------------- | --------- | -------------------------------------------------------------------------------- | -------------------------------------------------------------------------- |
| Binary-Artifacts       | 10        | No binaries found in the repo.                                                   | None                                                                       |
| Branch-Protection      | -1        | -                                                                                | None                                                                       |
| CI-Tests               | 10        | 30 out of 30 merged PRs checked by a CI test.                                    | None                                                                       |
| CII-Best-Practices     | 0         | No effort to earn an OpenSSF best practices badge detected.                      | None                                                                       |
| Code-Review            | 10        | All changesets reviewed.                                                         | None                                                                       |
| Contributors           | 10        | Project has 11 contributing companies or organizations.                          | Found contributions from: IBM, ImperialCQD, Qiskit, etc.                   |
| Dangerous-Workflow     | 10        | No dangerous workflow patterns detected.                                         | None                                                                       |
| Dependency-Update-Tool | 10        | Update tool detected.                                                            | Detected tool: Dependabot: `.github/dependabot.yml`.                       |
| Fuzzing                | 0         | Project is not fuzzed.                                                           | Warn: No fuzzer integrations found.                                        |
| License                | 10        | License file detected.                                                           | License: Apache License 2.0.                                               |
| Maintained             | 10        | Actively maintained with 30 commits and 18 issue activities in the last 90 days. | None                                                                       |
| Packaging              | 10        | Packaging workflow detected.                                                     | Found packaging via GitHub Actions.                                        |
| Pinned-Dependencies    | 0         | Dependencies not pinned by hash.                                                 | Various warnings about unpinned dependencies in workflows and scripts.     |
| SAST                   | 0         | SAST tool not run on all commits.                                                | Warn: 0 commits out of 30 checked with a SAST tool.                        |
| Security-Policy        | 10        | Security policy file detected.                                                   | Found `SECURITY.md` with linked content and disclosure information.        |
| Signed-Releases        | -1        | No releases found.                                                               | None                                                                       |
| Token-Permissions      | 0         | GitHub workflow tokens with excessive permissions detected.                      | Various warnings about insufficiently restricted permissions in workflows. |
| Vulnerabilities        | 0         | Project has known vulnerabilities.                                               |


### Ease of Use
RustworkX is a Python package and thus easily installable. Its documentation is complete and up-to-date, including introductory tutorials, API references, tools for NetworkX users, contribution guidelines, and documentation generation.
It is distributed on PyPI with binaries available for multiple operating systems, which facilitates immediate integration. Although RustworkX has not yet reached the historical popularity of NetworkX, it shows growing adoption and an expanding community on GitHub. Communication channels include Slack and IRC.

### Performance
It is the most efficient tool in the set, with a total runtime of **1.063 seconds** and **176,264 function calls**. As with NetworkX, most time is spent on node and edge insertions, but its Rust backend optimizes memory and CPU usage by minimizing the overhead of each operation. This results in faster insertions per node or edge. Profiling shows optimal resource usage with stable and low cost in critical functions.

---

## PyGraph

### Functionality
While PyGraph supports working with directed and undirected graphs and provides many common graph algorithms, it does **not** support attributes on nodes or edges, which was an essential requirement for this project. This limitation led to the addition of more edges than necessary, since no filtering could be applied to decide whether to add an edge between certain nodes.

### Scorecard
The scorecard result, as of 2025-01-06, using commit `25d004d3706778fd6fbf4b687d832bcbd4281002`, was **2.6**.


| **Check Name** | **Score** | **Reason** | **Details** |
|-------------------------|-----------|-------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| **Code-Review** | 1 | Found 3/27 approved changesets -- score normalized to 1 | - |
| **Maintained** | 0 | 0 commit(s) and 0 issue activity found in the last 90 days -- score normalized to 0 | - |
| **Dangerous-Workflow** | -1 | no workflows found | - |
| **Packaging** | -1 | packaging workflow not detected | Warn: no GitHub/GitLab publishing workflow detected |
| **Token-Permissions** | -1 | No tokens found | - |
| **Binary-Artifacts** | 10 | no binaries found in the repo | - |
| **Pinned-Dependencies** | -1 | no dependencies found | - |
| **CII-Best-Practices** | 0 | no effort to earn an OpenSSF best practices badge detected | - |
| **Security-Policy** | 0 | security policy file not detected | Warn: no security policy file detected |
| **Fuzzing** | 0 | project is not fuzzed | Warn: no fuzzer integrations found |
| **Vulnerabilities** | 10 | 0 existing vulnerabilities detected | - |
| **License** | 10 | license file detected | Info: project has a license file: LICENSE:0<br>Info: FSF or OSI recognized license: MIT License: LICENSE:0 |
| **Signed-Releases** | -1 | no releases found | - |
| **Branch-Protection** | 0 | branch protection not enabled on development/release branches | Warn: branch protection not enabled for branch 'master' |
| **SAST** | 0 | SAST tool is not run on all commits -- score normalized to 0 | Warn: 0 commits out of 6 are checked with a SAST tool |


### Ease of Use
PyGraph has no official documentation, so learning how to use it requires studying the repository. It only provides information about installation (which is simple) and about the algorithms it offers. The repository itself acknowledges that the library is no longer under active development and lacks documentation.

### Performance
PyGraph achieved a runtime of **1.314 seconds** with **197,1058 function calls**. The cost is concentrated in basic node and edge creation operations, which have a very low overhead. This makes PyGraph an attractive alternative for building large graphs in memory, provided that no extra metadata is required for nodes or edges.

---
## Graph-tool

### Functionality
Graph-tool meets the project requirements, as it allows the creation of graphs with attributes for both nodes and edges. It also provides a wide range of functionalities for analyzing and visualizing graphs.

### Scorecard
The scorecard result, as of 2025-01-17, using commit `f5a34b9a7ed578b082a774e82bea057ae6c6a43b`, was **3.9**.
The following table shows a more detailed analysis.


| Check Name | Score | Reason | Details |
|------------------------|-------|-----------------------------------------------|----------------------------------------------------------------------------------------------------------|
| Binary-Artifacts | 10 | no binaries found in the repo | - |
| Branch-Protection | 0 | branch protection not enabled on development/release branches | Warn: branch protection not enabled for branch 'master' |
| CI-Tests | -1 | no pull request found | - |
| CII-Best-Practices | 0 | no effort to earn an OpenSSF best practices badge detected | - |
| Code-Review | 0 | Found 0/30 approved changesets -- score normalized to 0 | - |
| Contributors | 0 | project has 0 contributing companies or organizations -- score normalized to 0 | - |
| Dangerous-Workflow | -1 | no workflows found | - |
| Dependency-Update-Tool | 0 | no update tool detected | Warn: no dependency update tool configurations found |
| Fuzzing | 0 | project is not fuzzed | Warn: no fuzzer integrations found |
| License | 10 | license file detected | Info: project has a license file: COPYING:0, Info: FSF or OSI recognized license: GNU General Public License v3.0 only: COPYING:0 |
| Maintained | 10 | 30 commit(s) and 0 issue activity found in the last 90 days -- score normalized to 10 | - |
| Packaging | 10 | packaging workflow detected | Info: Project packages its releases by way of GitHub Actions.: gitlabscorecard_flattened_ci.yaml:1819 |
| Pinned-Dependencies | 0 | dependency not pinned by hash detected -- score normalized to 0 | Warn: containerImage not pinned by hash: release/debian/Dockerfile:3, release/debian/Dockerfile:55, release/docker/Dockerfile:3, release/docker/Dockerfile:39: pin your Docker image by updating archlinux:latest to archlinux:latest@sha256:4ec00881e67eaf063c4e8d4f3a7e47eb7bc5de77edfd45477e0c6a734a60eb51, Info: 0 out of 4 containerImage dependencies pinned |
| SAST | 0 | no SAST tool detected | Warn: no pull requests merged into dev branch |
| Security-Policy | 0 | security policy file not detected | Warn: no security policy file detected, no security file to analyze (repeated warnings) |
| Signed-Releases | -1 | no releases found | - |
| Token-Permissions | -1 | No tokens found | - |
| Vulnerabilities | 10 | 0 existing vulnerabilities detected | - |


### Ease of Use
During installation, several difficulties arose: since the development environment was based on Python managed with Poetry, integrating Graph-tool proved impossible because it is not directly available on PyPI and depends on external C++ libraries (mainly Boost). This caused incompatibilities that made local installation in the usual development environment unfeasible.
As a workaround, experiments were executed in **Google Colab**, where Graph-tool could be installed more easily using precompiled packages.

Its official documentation is well-structured and detailed, with complete descriptions of classes, methods, and usage examples. However, since it relies on generic programming concepts from C++, some operations are less intuitive for Python users.
The community is smaller compared to the previous tools. While there is an active forum, it is mainly maintained by the tool’s creator (unlike NetworkX or RustworkX), as is the main repository.

### Performance
Thanks to its C++ backend, Graph-tool should have efficient performance and stable memory usage when handling large graphs. However, in this case, its performance may have been affected by running in a virtual environment, resulting in **6.074 seconds** of runtime with **3,095,995 function calls**.

## Neo4j

### Functionality
Neo4j allows the creation of nodes and relationships with properties. It also includes a graph-specific query language (**Cypher**), built-in analysis algorithms, indexes, and constraints to optimize queries.

### Scorecard
The scorecard result, as of 2025-01-13, using commit `e66ff235a138b844e4f80903e81107dbadeb4956`, was **6.1**.
The following table shows a more detailed analysis.

| **Check Name** | **Score** | **Reason** | **Details** |
|---------------------------|-----------|------------------------------------------------------------------------------------------------|-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| Binary-Artifacts | 10 | No binaries found in the repo | - |
| Branch-Protection | -1 | - | - |
| CI-Tests | 10 | 29 out of 29 merged PRs checked by a CI test -- score normalized to 10 | - |
| CII-Best-Practices | 0 | No effort to earn an OpenSSF best practices badge detected | - |
| Code-Review | 9 | Found 28/29 approved changesets -- score normalized to 9 | - |
| Contributors | 10 | Project has 6 contributing companies or organizations | Info: found contributions from: elastic, gnustep, neo technology, neo4j, stripe, tibber |
| Dangerous-Workflow | -1 | No workflows found | - |
| Dependency-Update-Tool | 0 | No update tool detected | Warn: no dependency update tool configurations found |
| Fuzzing | 0 | Project is not fuzzed | Warn: no fuzzer integrations found |
| License | 9 | License file detected | Warn: project license file does not contain an FSF or OSI license. Info: project has a license file: LICENSE.txt:0 |
| Maintained | 10 | 20 commit(s) and 3 issue activity found in the last 90 days -- score normalized to 10 | - |
| Packaging | -1 | Packaging workflow not detected | Warn: no GitHub/GitLab publishing workflow detected. |
| Pinned-Dependencies | 0 | Dependency not pinned by hash detected -- score normalized to 0 | Warn: containerImage not pinned by hash: benchkit/Dockerfile:1: pin your Docker image by updating python:3.12 to python:3.12@sha256:5893362478144406ee0771bd9c38081a185077fb317ba71d01b7567678a89708 |
| SAST | 0 | SAST tool is not run on all commits -- score normalized to 0 | Warn: 0 commits out of 30 are checked with a SAST tool |
| Security-Policy | 10 | Security policy file detected | Info: security policy file detected: github.com/neo4j/.github/SECURITY.md:1 |
| Signed-Releases | -1 | No releases found | - |
| Token-Permissions | -1 | No tokens found | - |
| Vulnerabilities | 10 | 0 existing vulnerabilities detected | - |


### Ease of Use
Neo4j is not a pure Python library, but a graph database management system. It cannot be installed as a simple Python package but instead runs as a standalone database server to which client applications connect.
Installation options include running Neo4j in a container, manually installing the community server version, or using the desktop version. For these tests, the desktop version was used, as it allows running quick queries without additional setup. Neo4j also provides an intuitive graphical interface, simplifying database management tasks such as creation, start, and shutdown of graph databases.

Its documentation is extensive and well-structured, with step-by-step tutorials, query examples, and technical reference manuals. As one of the most widely adopted graph tools worldwide, it provides educational resources, online courses, and official workshops, making it accessible to both beginners and advanced users.

### Performance
Neo4j is considerably slower than the other tools, with a total runtime of **3,156 seconds** (52 minutes and 36 seconds) and **563,021,881 function calls**. The high number of calls and execution time spent on network operations indicate that the bottleneck lies in client-server communication and transaction overhead. Each node or edge insertion creates an independent transaction, which increases round-trips and message serialization/deserialization.
While Neo4j is ideal for complex queries and large-scale graph persistence, its performance in massive node and edge insertions is inefficient.

---


# Conclusion

Based on the results, it can be concluded that the best options were **NetworkX** and **RustworkX**, as both provide excellent documentation and a wide range of useful functionalities. However, when comparing performance, **RustworkX** demonstrated a significant advantage in efficiency, whereas **NetworkX** presents limitations in terms of scalability. In scenarios where it is necessary to work with larger graphs, it is expected that NetworkX will lose viability due to efficiency concerns. Therefore, **RustworkX** is the most suitable alternative for the development of the tool.

---
