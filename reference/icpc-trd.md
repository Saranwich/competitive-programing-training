# ICPC Team Reference Document — ฉบับใช้จริง

งบ: 25 หน้า (หน้าเดียว, หลังกระดาษ = ที่ทด) • ใช้เต็ม 25 หน้า
เส้นแบ่ง `---` = ขึ้นหน้าใหม่ตอนปริ๊นท์
หน้า 2–18 = ของที่ใช้เป็นแล้ว • หน้า 19–24 = ชุดขยาย (แต่ละตัวต่อยอดจากของที่ใช้เป็น) • หน้า 25 = ตารางเลือก algo

---

## หน้า 1 — ปก (ฟอร์แมตเดียวกับตัวอย่างสนาม)

> [โลโก้มหาวิทยาลัย]
>
> **Thammasat University**
> **ICPC Reference Document**
>
> **[ชื่อทีม — กรอก]**
>
> Department of Computer Science
> Faculty of Science and Technology
> Thammasat University (Rangsit Campus)

---

## หน้า 2 — หาของอยู่ตรงไหน (เปิดหน้านี้ก่อนเสมอ)

**สารบัญ:** 3 vector • 4 string • 5 set/multiset • 6 map • 7 queue/deque/stack • 8 priority_queue+pair/tuple • 9 ฟังก์ชัน algorithm • 10 การอ่าน input • 11 binary search • 12 two pointers/prefix • 13 greedy • 14 DP • 15 BFS • 16 DSU • 17 math • 18 ตาราง n→algo + brute force • 19 Dijkstra • 20 Floyd+Kruskal • 21 DFS • 22 toposort • 23 knapsack • 24 LCS/LIS • 25 (หลังสุด) โจทย์→algo

**ตารางหลัก: อยากหา "ค่า/ตำแหน่ง" → ใช้อะไร → ไม่เจอได้อะไร**

| อยากทำ | เขียน | ไม่เจอคืนอะไร | เร็ว |
|---|---|---|---|
| ตำแหน่งแรกที่ ≥ x (vector **sort แล้ว**) | `lower_bound(v.begin(),v.end(),x)` | `v.end()` | log n |
| ตำแหน่งแรกที่ > x (sort แล้ว) | `upper_bound(v.begin(),v.end(),x)` | `v.end()` | log n |
| มี x ไหม (sort แล้ว) | `binary_search(v.begin(),v.end(),x)` | `false` | log n |
| ตำแหน่งของ x (**ยังไม่ sort**) | `find(v.begin(),v.end(),x)` | `v.end()` | n |
| มี x ไหม ใน set/multiset | `s.count(x)` | `0` | log n |
| iterator ของ x ใน set | `s.find(x)` | `s.end()` | log n |
| ตัวแรก ≥ x ใน set | `s.lower_bound(x)` ← **member!** | `s.end()` | log n |
| มี key ไหม ใน map | `m.count(k)` | `0` | log n |
| ตำแหน่งคำใน string | `s.find("ab")` | `string::npos` | n·m |

```cpp
// แปลง iterator → index:   int idx = it - v.begin();   (ถ้า idx == v.size() = ไม่เจอ)
// เอาค่า:                  *it        (ห้าม * ตัว end() เด็ดขาด — เช็คก่อนเสมอ)
// ตัวใหญ่สุดที่ ≤ x:       auto it = upper_bound(...); if (it != v.begin()) --it; ค่าคือ *it
//                          ถ้า it == v.begin() ตั้งแต่แรก = ไม่มีตัวไหน ≤ x
```

> ⚠ `std::lower_bound(s.begin(), s.end(), x)` กับ set = O(n) ช้ามาก — set/map ต้องใช้ตัว member `s.lower_bound(x)` เท่านั้น

---

## หน้า 3 — vector

```cpp
vector<ll> v;                  // ว่าง
vector<ll> v(n);               // n ตัว ค่า 0
vector<ll> v(n, x);            // n ตัว ค่า x
vector<ll> v = {1, 2, 3};
vector<vector<ll>> g(R, vector<ll>(C, 0));   // 2D R แถว C คอลัมน์

v.push_back(x);                // เพิ่มท้าย O(1)
v.pop_back();                  // ลบท้าย O(1) — ไม่คืนค่า! อ่าน v.back() ก่อน
v[i]                           // อ่าน/เขียน ตำแหน่ง i — ถ้า i เกิน = พังเงียบ (UB)
v.front(); v.back();           // ตัวแรก / ตัวท้าย (ห้ามเรียกตอนว่าง)
v.size(); v.empty();
v.clear();                     // ล้างหมด
v.resize(n);                   // ปรับขนาด (ตัวใหม่ = 0)
v.assign(n, x);                // ล้างแล้วเติม n ตัวค่า x

v.insert(v.begin() + i, x);    // แทรกที่ i — O(n) ช้า! ห้ามทำใน loop
v.erase(v.begin() + i);        // ลบที่ i — O(n) ช้า! ห้ามทำใน loop
// ต้อง insert/erase บ่อย → เปลี่ยนไปใช้ set หรือ deque

// วน:
for (ll x : v)                 // อ่านอย่างเดียว
for (ll& x : v) x *= 2;        // แก้ค่า ต้องมี &
for (int i = 0; i < (int)v.size(); i++)
```

> ⚠ `v.size()` เป็น unsigned: ถ้า v ว่าง `v.size() - 1` = เลขมหาศาล ไม่ใช่ -1 → loop เพี้ยน แคสต์ `(int)v.size()` เสมอเวลาลบ
> ⚠ `pop_back` ตอนว่าง / `back()` ตอนว่าง = พัง เช็ค `!v.empty()` ก่อน

---

## หน้า 4 — string

```cpp
string s = "hello";
s.size(); s.empty(); s[i];     // เหมือน vector
s += 'x';                      // ต่อท้าย 1 ตัว O(1)
s += t;                        // ต่อ string O(len t)
s = s + t;                     // O(ทั้งก้อน) — ใน loop ใช้ += เท่านั้น!

s.substr(pos, len)             // ตัด: เริ่ม pos ยาว len — len เกินท้าย = ได้เท่าที่มี (ไม่พัง)
                               // แต่ pos > s.size() = พังทันที (out_of_range)!
s.substr(pos)                  // ตั้งแต่ pos ถึงจบ
s.find("ab")                   // ตำแหน่งแรกที่เจอ — ไม่เจอ → string::npos
s.find("ab", start)            // เริ่มหาจาก start
if (s.find(t) != string::npos) // วิธีเช็คว่ามี
s.rfind("ab")                  // หาจากท้าย

reverse(s.begin(), s.end());
sort(s.begin(), s.end());      // เรียงตัวอักษร (เทียบ anagram: sort สองฝั่งแล้ว ==)
s == t; s < t;                 // เทียบตามพจนานุกรมได้เลย

// แปลงชนิด
stoll(s)     // string → long long — ถ้า s ไม่ใช่ตัวเลข = พังทันที! (เช็คก่อนถ้าไม่ชัวร์)
stoi(s)      // string → int (ระวังเกิน int)
to_string(x) // ตัวเลข → string

// ตัวอักษรเดี่ยว ↔ ตัวเลข
char c = '7';  int d = c - '0';     // '7' → 7
char c = 'e';  int i = c - 'a';     // 'e' → 4  (index 0..25)
char C = 'a' + i;                    // ย้อนกลับ
isdigit(c); isalpha(c); islower(c); isupper(c);
tolower(c); toupper(c);              // คืน int — เขียน char(tolower(c))

// นับความถี่
int cnt[26] = {0};
for (char c : s) cnt[c - 'a']++;

// palindrome
string r = s; reverse(r.begin(), r.end());
bool pal = (s == r);
```

---

## หน้า 5 — set / multiset (เรียงให้อัตโนมัติ, ทุกอย่าง O(log n))

```cpp
set<ll> s;                     // เก็บค่าไม่ซ้ำ + เรียงเสมอ
multiset<ll> ms;               // เหมือน set แต่ซ้ำได้

s.insert(x);                   // set: ถ้ามีอยู่แล้ว = เฉยๆ ไม่เพิ่ม
s.erase(x);                    // ลบ (set: ตัวเดียว)
s.count(x);                    // set: 0/1
s.size(); s.empty();
*s.begin();                    // ตัวเล็กสุด
*s.rbegin();                   // ตัวใหญ่สุด
*prev(s.end());                // ตัวใหญ่สุด (อีกวิธี)

auto it = s.find(x);           // ไม่เจอ → s.end()
auto it = s.lower_bound(x);    // ตัวแรก ≥ x — ไม่เจอ → s.end()
auto it = s.upper_bound(x);    // ตัวแรก > x — ไม่เจอ → s.end()
// ตัวใหญ่สุดที่ ≤ x:  it = s.upper_bound(x); if (it != s.begin()) --it;

// วน (ได้ค่าจากน้อยไปมาก):
for (ll x : s) ...
```

> ⚠ **multiset:** `ms.erase(x)` ลบ**ทุกตัว**ที่เท่ากับ x! ลบตัวเดียว → `ms.erase(ms.find(x))`
> ⚠ ลบระหว่างวน: `it = s.erase(it);` (erase คืน iterator ตัวถัดไป) — ห้าม `s.erase(it); it++;`
> ⚠ ห้ามแก้ค่าที่อยู่ใน set (มันจะไม่เรียงใหม่) — ลบออกแล้ว insert ตัวใหม่แทน
> `multiset.count(x)` ช้าถ้าซ้ำเยอะ (O(log n + จำนวนซ้ำ)) — ปกติไม่มีปัญหา

---

## หน้า 6 — map (key→value, key เรียงให้อัตโนมัติ, O(log n))

```cpp
map<ll,ll> m;                  // key ชนิดไหนก็ได้ที่เทียบ < ได้: string, pair ก็ได้
m[k] = v;                      // ใส่ / ทับ
m[k]++;                        // นับความถี่ — key ยังไม่มี = สร้างให้เป็น 0 แล้ว ++ อัตโนมัติ
m.count(k);                    // มี key ไหม → 0/1
m.erase(k);
m.size(); m.empty();

auto it = m.find(k);           // ไม่เจอ → m.end()
// it->first = key, it->second = value
m.lower_bound(k); m.upper_bound(k);   // เหมือน set (member function)
m.begin()->first;              // key เล็กสุด
m.rbegin()->first;             // key ใหญ่สุด

// วน (เรียงตาม key เสมอ):
for (auto& [k, v] : m) cout << k << " " << v << "\n";
```

> ⚠ **กับดักใหญ่สุดของ map:** แค่ "อ่าน" `m[k]` ก็**สร้าง key นั้นทิ้งไว้** (ค่า 0)! เช็คเฉยๆ ต้องใช้ `m.count(k)` — ไม่งั้น size โต, วนเจอ key ผี
> ⚠ **unordered_map:** เฉลี่ย O(1) แต่โดน test แกล้งให้ช้าเป็น O(n) ได้ (เจอมาแล้วใน Codeforces TLE) → **ใช้ map ธรรมดาเสมอ** ยกเว้นมั่นใจว่าจำเป็น
> key เป็น `pair<ll,ll>` ได้เลย: `map<pair<ll,ll>, ll> m; m[{x,y}]++;`

---

## หน้า 7 — queue / deque / stack

```cpp
queue<int> q;                  // แถว: เข้าท้าย-ออกหัว (ใช้ใน BFS)
q.push(x);                     // เข้าท้าย
q.front();                     // ดูหัวแถว (ไม่เอาออก)
q.pop();                       // เอาหัวแถวออก — ไม่คืนค่า! อ่าน front() ก่อน
q.back(); q.size(); q.empty();

stack<int> st;                 // ตั้งกอง: เข้า-ออกทางเดียว (ล่าสุดออกก่อน)
st.push(x); st.top(); st.pop(); st.empty();
// ใช้กับ: จับคู่วงเล็บ, undo, "ตัวล่าสุดที่ยังไม่ถูกจับคู่"

deque<int> d;                  // เข้า-ออกได้สองหัว O(1) + index ได้เหมือน vector
d.push_back(x);  d.push_front(x);
d.pop_back();    d.pop_front();
d.front(); d.back(); d[i]; d.size();
// ใช้เมื่อ: อยากได้ queue ที่ index ได้ / เพิ่ม-ลบทั้งหัวและท้าย
```

> ⚠ ทั้งสามตัว: `pop()` ไม่คืนค่า — อ่านค่าด้วย `front()`/`top()` ก่อนแล้วค่อย pop
> ⚠ เรียก front/top/pop ตอนว่าง = พังเงียบ → `while (!q.empty())` หรือเช็คก่อนทุกครั้ง
> queue/stack วนดูข้างในไม่ได้ (ต้อง pop ออกอย่างเดียว) — อยากวนดู → ใช้ deque

---

## หน้า 8 — priority_queue (heap) + pair / tuple / array

```cpp
priority_queue<ll> mx;                          // MAX-heap: top = ใหญ่สุด (default)
priority_queue<ll, vector<ll>, greater<>> mn;   // MIN-heap: top = เล็กสุด ← จำ syntax นี้!
mn.push(x);
mn.top();                      // ดูยอด — ไม่เอาออก
mn.pop();                      // เอายอดออก — ไม่คืนค่า
mn.size(); mn.empty();
// มีแค่นี้จริงๆ: ไม่มี index, วนดูไม่ได้, หาตัวอื่นไม่ได้
// อยากลบตัวที่ไม่ใช่ยอด / หาค่ากลางๆ → ใช้ multiset แทน (มี begin/rbegin/find/erase)

// เก็บของพ่วง: {key, id} — เทียบตัวแรกก่อนเสมอ → เอา key ไว้หน้า
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;
pq.push({dist, node});
auto [d, u] = pq.top(); pq.pop();

pair<ll,ll> p = {a, b};
p.first; p.second;
auto [x, y] = p;               // แตกเป็นตัวแปร (structured bindings)

tuple<ll,ll,ll> t = {a, b, c};
get<0>(t); get<2>(t);
auto [x, y, z] = t;

array<ll,3> a3 = {key, val, idx};   // เบากว่า tuple + index ได้ a3[0]
// pair / tuple / array<ll,N> เทียบกันแบบพจนานุกรม (ตัวแรกก่อน)
// → ใส่ vector แล้ว sort ได้เลย, ใส่ heap ได้เลย โดยเอาตัวที่อยากเรียงไว้หน้า
```

---

## หน้า 9 — ฟังก์ชันใน `<algorithm>` (ใช้กับ vector/string/array)

```cpp
sort(v.begin(), v.end());                      // น้อย→มาก O(n log n)
sort(v.begin(), v.end(), greater<>());         // มาก→น้อย
sort(v.begin(), v.end(), [](auto& a, auto& b){ // custom: คืน true ถ้า a ต้องมาก่อน b
    return tie(a.second, a.first) < tie(b.second, b.first);  // เรียงตาม second ก่อน
});
// ⚠ comparator ต้องเป็น "น้อยกว่าจริง" — ใช้ <= = พังแบบสุ่ม! ใช้ < เท่านั้น

reverse(v.begin(), v.end());
min(a, b); max(a, b); min({a, b, c});          // หลายตัวใส่ปีกกา
swap(a, b);
auto it = max_element(v.begin(), v.end());     // iterator ตัวใหญ่สุด → ค่า = *it
auto it = min_element(v.begin(), v.end());     //   ตำแหน่ง = it - v.begin()
accumulate(v.begin(), v.end(), 0LL);           // ผลรวม — ต้อง 0LL ไม่งั้น overflow!
count(v.begin(), v.end(), x);                  // นับตัวที่ == x, O(n)
fill(v.begin(), v.end(), x);                   // เติมค่าเดียวทั้งอาเรย์
iota(v.begin(), v.end(), 0);                   // เติม 0,1,2,...
abs(x); __builtin_popcountll(x);               // นับ bit ที่เป็น 1 (long long)

// ลบตัวซ้ำ (ต้อง sort ก่อน):
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());

// ลอง permutation ทุกแบบ (v ต้องเริ่มจาก sort แล้ว):
sort(v.begin(), v.end());
do { ... } while (next_permutation(v.begin(), v.end()));
```

---

## หน้า 10 — การอ่าน input (โจทย์เล่าเรื่อง = ต้องแกะ input ให้เป็น)

```cpp
// หัวไฟล์มาตรฐาน
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);   // กัน TLE จาก I/O
    ...
}

cin >> n;                      // อ่านทีละตัว ข้าม space/ขึ้นบรรทัดให้เอง
cin >> a >> b >> s;            // ผสมชนิดได้

// อ่านทั้งบรรทัด (มี space ข้างใน):
cin >> n;
cin.ignore();                  // ← ห้ามลืม! กิน '\n' ค้าง ไม่งั้น getline ได้บรรทัดว่าง
getline(cin, line);

// แยกบรรทัดเป็นคำ:
stringstream ss(line);
string w;
while (ss >> w) words.push_back(w);

// แยกด้วยตัวคั่นอื่น เช่น ',':
stringstream ss(line);
string tok;
while (getline(ss, tok, ',')) parts.push_back(tok);

// ไม่บอกจำนวน อ่านจนหมด:
while (cin >> x) { ... }

// ปริ๊นท์
cout << x << " " << y << "\n";           // ใช้ "\n" — endl ช้า (flush ทุกครั้ง) TLE ได้
cout << fixed << setprecision(6) << d;   // ทศนิยม 6 ตำแหน่ง
cout << (cond ? "YES" : "NO") << "\n";   // ⚠ ternary ต้องมีวงเล็บ! << แย่งก่อน ?:
```

---

## หน้า 11 — Binary Search (จุดตาย: ปัดขึ้น/ปัดลง)

```cpp
// แบบ 1: หา x "น้อยสุด" ที่ ok(x) จริง   (หน้าตา F F F T T T)
ll lo = ต่ำสุดที่เป็นไปได้, hi = สูงสุดที่ ok แน่ๆ;
while (lo < hi) {
    ll mid = lo + (hi - lo) / 2;         // ปัดลง
    if (ok(mid)) hi = mid;
    else lo = mid + 1;
}
// จบ: lo == hi == คำตอบ

// แบบ 2: หา x "ใหญ่สุด" ที่ ok(x) จริง   (หน้าตา T T T F F F)
while (lo < hi) {
    ll mid = lo + (hi - lo + 1) / 2;     // ⚠ ปัดขึ้น! ใช้ปัดลง = loop ค้างไม่จบ
    if (ok(mid)) lo = mid;
    else hi = mid - 1;
}
```

**Binary search on answer** — สัญญาณ: โจทย์ถาม "น้อยสุด/มากสุดเท่าไหร่ที่ทำได้" และการเช็ค "ค่า t นี้ทำได้ไหม" ง่ายกว่าหาคำตอบตรงๆ
→ เขียน `ok(t)` แล้วครอบด้วยแบบ 1 หรือ 2

- ok ต้อง monotone: จริงแล้วจริงตลอดทาง (เช็คในหัวก่อนใช้)
- ใน ok(t) ระวังผลรวม overflow → สะสมเป็น ll และ break เมื่อเกินเป้าแล้ว
- `(lo + hi) / 2` ตรงๆ overflow ได้ถ้าทั้งคู่ใหญ่ → ใช้ `lo + (hi - lo) / 2`

---

## หน้า 12 — Two Pointers / Prefix Sum (บรรทัดเสี่ยง)

```cpp
// sliding window: subarray ผลรวม = x — ใช้ได้เมื่อเลข "บวกล้วน" เท่านั้น
int l = 0; ll sum = 0, cnt = 0;
for (int r = 0; r < n; r++) {
    sum += a[r];
    while (sum > x) sum -= a[l++];
    if (sum == x) cnt++;
}

// มีเลขติดลบ → sliding window ใช้ไม่ได้ ต้อง prefix + map:
map<ll,ll> seen; seen[0] = 1;      // ⚠ seed prefix ว่าง — ลืม = ผิดทุกเคสที่ prefix == x
ll pre = 0, cnt = 0;
for (int i = 0; i < n; i++) {
    pre += a[i];
    cnt += seen[pre - x];
    seen[pre]++;
}

// prefix sum 1D: ถามผลรวมช่วงหลายรอบ (ไม่มีแก้ค่า)
vector<ll> pre(n + 1, 0);
for (int i = 1; i <= n; i++) pre[i] = pre[i-1] + a[i-1];
// ผลรวม [l..r] (1-indexed) = pre[r] - pre[l-1]

// จับคู่สองอาเรย์ (sort ทั้งคู่ก่อน) เช่น ของชิ้นใกล้กันไม่เกิน k:
int i = 0, j = 0;
while (i < n && j < m) {
    if (abs(a[i] - b[j]) <= k) { cnt++; i++; j++; }
    else if (a[i] < b[j]) i++;
    else j++;
}
```

---

## หน้า 13 — Greedy (จุดตัดสิน: sort key อะไร เพราะอะไร — พูดออกเสียงก่อนเขียน)

```cpp
// [เลือกกิจกรรมมากสุดไม่ทับกัน] → sort ตาม "เวลาจบ" น้อยก่อน
// เก็บ {end, start} จะได้ sort ตรงๆ
sort(v.begin(), v.end());
ll cnt = 0, cur = -1e18;
for (auto& [e, s] : v)
    if (s >= cur) { cnt++; cur = e; }    // ⚠ cur = e ไม่ใช่ cur += e (เคยพลาด!)

// [ซ้อนกันมากสุด ณ จุดเดียว / ต้องใช้กี่ห้อง] → event sweep ±1
map<ll,ll> d;
d[a]++; d[b]--;                          // แต่ละช่วง [a,b) — นับรวมปลาย → d[b+1]--
ll cur = 0, best = 0;
for (auto& [t, c] : d) { cur += c; best = max(best, cur); }

// [k คน เลือกงานรวมกันมากสุด] → sort ตามจบ + multiset เวลาว่าง
multiset<ll> avail;
for (int i = 0; i < k; i++) avail.insert(0);
for (auto& [e, s] : v) {                 // v sort ตาม end แล้ว
    auto it = avail.upper_bound(s);      // ตัวแรก > s
    if (it == avail.begin()) continue;   // ไม่มีใครว่างทัน
    --it;                                // คนว่าง "ช้าสุดที่ยังทัน"
    avail.erase(it); avail.insert(e); cnt++;
}

// [Σ เวลารอน้อยสุด] → ทำงานสั้นสุดก่อน (sort ตาม duration)
// [เหรียญ: ค่าน้อยสุดที่สร้างไม่ได้] → sort แล้วไล่ reach:
//    ถ้า c > reach + 1 → ตอบ reach + 1   ไม่งั้น reach += c
```

**เช็คก่อนเชื่อ greedy:** ลองหา counterexample 10 วินาที ถ้าสลับลำดับที่เลือกแล้ว "อาจดีกว่า" ได้ → ไม่ใช่ greedy, เป็น DP (เช่นเหรียญ {1,3,4} จ่าย 6: โลภ 4+1+1 แพ้ 3+3)

---

## หน้า 14 — DP (ตอบ 5 ข้อในหัวก่อน แล้วค่อยแตะคีย์บอร์ด)

```
1) state:  dp[i] คืออะไร (พูดเป็นประโยคเดียว)     2) transition
3) base:   นับวิธี → dp[0] = 1   |   หา min → dp[0] = 0
4) order:  เล็ก → ใหญ่                            5) answer อยู่ช่องไหน
```

```cpp
// นับจำนวนวิธี (คำตอบ mod 1e9+7):
const ll MOD = 1e9 + 7;
vector<ll> dp(x + 1, 0); dp[0] = 1;
for (int i = 1; i <= x; i++)
    for (ll c : coins)
        if (i - c >= 0) dp[i] = (dp[i] + dp[i-c]) % MOD;   // mod ใน loop เลย

// หาค่าน้อยสุด:
const ll INF = 1e18;                      // ⚠ INF = บวกใหญ่ (เคยพลาดใส่ -1e9)
vector<ll> dp(x + 1, INF); dp[0] = 0;
for (int i = 1; i <= x; i++)
    for (ll c : coins)
        if (i - c >= 0 && dp[i-c] != INF)          // ⚠ guard INF ก่อนบวก
            dp[i] = min(dp[i], dp[i-c] + 1);       // ⚠ ใช้ min() — เขียนเทียบเองเคยกลับทิศ
cout << (dp[x] == INF ? -1 : dp[x]);

// ลำดับ loop = ความหมาย:
// "ลำดับต่างกันนับแยก"  → for i { for c { dp[i] += dp[i-c] } }   (sum นอก)
// "เซตเดียวนับครั้งเดียว" → for c { for i { dp[i] += dp[i-c] } }   (เหรียญนอก)

// ต้องเพิ่มมิติเมื่อ: การเลือกตัวถัดไปขึ้นกับ "ค่าล่าสุด" → ค่านั้นเป็นมิติ dp[i][v]
```

**bug ประจำตัว (ไล่ก่อน submit):** ① ขนาด array — n หรือ x? (พลาด 3 รอบ) ② ทิศ min ③ INF บวกใหญ่ + guard ④ `>= 0` ไม่ใช่ `> 0` ⑤ mod ใน loop ⑥ recursion ลึก 1e6 = stack overflow → เขียน loop เสมอ

---

## หน้า 15 — BFS (ระยะสั้นสุดเมื่อทุกก้าวราคาเท่ากัน)

```cpp
// กราฟโหนด 1..n จาก edge list:
vector<vector<int>> adj(n + 1);
for (int i = 0; i < m; i++) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);       // มีทิศทาง → ตัดบรรทัดนี้
}

vector<int> dist(n + 1, -1);   // -1 = ยังไปไม่ถึง
queue<int> q;
dist[s] = 0; q.push(s);
while (!q.empty()) {
    int u = q.front(); q.pop();
    for (int v : adj[u])
        if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
}
// จบ: dist[v] = จำนวนก้าวน้อยสุด s→v,  ยัง -1 = ไปไม่ถึง
// อยากได้เส้นทาง: เก็บ par[v] = u ตอน push แล้วเดินย้อนจากปลายทาง
// นับกลุ่มที่เชื่อมกัน: วนทุกโหนด ถ้า dist ยัง -1 → BFS ใหม่ นับ +1

// BFS บนตาราง (เขาวงกต):
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
vector<vector<int>> dist(R, vector<int>(C, -1));
queue<pair<int,int>> q;
dist[sr][sc] = 0; q.push({sr, sc});
while (!q.empty()) {
    auto [r, c] = q.front(); q.pop();
    for (int k = 0; k < 4; k++) {
        int nr = r + dx[k], nc = c + dy[k];
        if (nr < 0 || nr >= R || nc < 0 || nc >= C) continue;   // นอกขอบ
        if (grid[nr][nc] == '#' || dist[nr][nc] != -1) continue; // กำแพง/เคยไป
        dist[nr][nc] = dist[r][c] + 1;
        q.push({nr, nc});
    }
}
```

สัญญาณใช้ BFS: "ก้าวน้อยสุด / ผ่านกี่ช่อง / ไปถึงได้ไหม" บนกราฟหรือตารางที่ทุกก้าวเท่ากัน

---

## หน้า 16 — DSU (Union-Find): "อยู่กลุ่มเดียวกันไหม" เกือบ O(1)

```cpp
vector<int> par, sz;
void dsu_init(int n) {
    par.resize(n + 1); sz.assign(n + 1, 1);
    iota(par.begin(), par.end(), 0);            // par[i] = i
}
int find(int x) {
    return par[x] == x ? x : par[x] = find(par[x]);
}
bool uni(int a, int b) {                        // รวมกลุ่ม a,b — คืน false ถ้ากลุ่มเดียวกันอยู่แล้ว
    a = find(a); b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a; sz[a] += sz[b];
    return true;
}
```

**วิธีใช้ (ไม่ต้องเข้าใจไส้ใน):**
- อยู่กลุ่มเดียวกันไหม → `find(a) == find(b)`
- ขนาดกลุ่มของ a → `sz[find(a)]`
- นับจำนวนกลุ่ม: เริ่ม = n, ทุกครั้งที่ `uni()` คืน true → ลด 1
- edge ไหนทำให้เกิดวงกลม → `uni(u,v)` คืน false = edge นั้นสร้าง cycle
- สัญญาณใช้: "เพิ่มถนน/สายไฟทีละเส้น แล้วถามว่าเชื่อมถึงกันไหม" ระหว่างทาง (BFS ตอบตอนจบได้ แต่ตอบระหว่างเพิ่มทีละเส้นไม่ไหว)

---

## หน้า 17 — Math

```cpp
ll g = gcd(a, b);                    // มีให้เลย (C++17)  gcd(a,0) = a
ll l = a / g * b;                    // lcm — ⚠ หารก่อนคูณ! a*b/g overflow

// (base^e) % MOD ใน O(log e):
const ll MOD = 1e9 + 7;
ll modpow(ll b, ll e, ll m) {
    ll r = 1; b %= m;
    while (e > 0) {
        if (e & 1) r = r * b % m;
        b = b * b % m;
        e >>= 1;
    }
    return r;
}

// "หาร" ภายใต้ mod → คูณ inverse (MOD ต้องเป็นจำนวนเฉพาะ):
ll inv(ll a) { return modpow(a, MOD - 2, MOD); }
// (x / y) % MOD  =  x % MOD * inv(y) % MOD

// จำนวนเฉพาะทุกตัว ≤ N:
vector<char> isp(N + 1, 1); isp[0] = isp[1] = 0;
for (ll i = 2; i * i <= N; i++)
    if (isp[i]) for (ll j = i * i; j <= N; j += i) isp[j] = 0;
// เช็คตัวเดียว: ลองหาร 2..√n พอ

// nCr % MOD (เตรียม fact ครั้งเดียว):
vector<ll> fact(N + 1); fact[0] = 1;
for (int i = 1; i <= N; i++) fact[i] = fact[i-1] * i % MOD;
ll nCr(ll n, ll r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv(fact[r]) % MOD * inv(fact[n-r]) % MOD;
}

// mod ติดลบ (C++ คืนติดลบได้!): ((a % m) + m) % m
```

| type | เก็บได้ | ตัวอย่างที่ระเบิด |
|---|---|---|
| int | ~2.1e9 | 1e5 × 1e5 = 1e10 เกินแล้ว |
| long long | ~9.2e18 | 1e9 × 1e9 รอด แต่คูณ 3 ตัวไม่รอด |

n ตัว × ค่าโตสุด: 2e5 × 1e9 = 2e14 → ต้อง ll เสมอ • เขียน `0LL`, `1LL << k`

---

## หน้า 18 — อ่าน n → รู้ว่าใช้อะไรได้ + brute force

เกณฑ์: ~1e8 คำสั่งง่ายๆ ต่อวินาที

| n ไม่เกิน | ใช้ได้ถึง | เครื่องมือ |
|---|---|---|
| 11 | O(n!) | ลอง permutation ทุกแบบ ↓ |
| 20 | O(2^n) | ลอง subset ทุกแบบ ↓ |
| 500 | O(n³) | DP 3 ชั้น |
| 5,000 | O(n²) | DP 2 ชั้น / เทียบทุกคู่ |
| 2e5 | O(n log n) | sort, set/map, heap, binary search |
| 1e7 | O(n) | prefix, two pointers, sieve |
| 1e9 ขึ้นไป | O(log n) | binary search on answer, สูตร math |

```cpp
// ลอง "ลำดับ" ทุกแบบ (n ≤ 11):
vector<int> p(n); iota(p.begin(), p.end(), 0);
do {
    // ใช้ p[0..n-1] เป็นลำดับ ประเมินคำตอบ เก็บ best
} while (next_permutation(p.begin(), p.end()));

// ลอง "เลือก/ไม่เลือก" ทุกแบบ (n ≤ 20):
for (int mask = 0; mask < (1 << n); mask++) {
    for (int i = 0; i < n; i++)
        if (mask >> i & 1) { /* ตัวที่ i ถูกเลือก */ }
}
// จำนวนตัวที่เลือก: __builtin_popcount(mask)
```

**ก่อนเขียนอะไรซับซ้อน ถามตัวเอง: n เท่าไหร่ — brute force ผ่านไหม?** (ผ่าน = เขียน brute force จบ อย่าประดิษฐ์)

---

## หน้า 19 — Dijkstra (BFS ที่ก้าวราคาไม่เท่ากัน)

*ต่อยอดจาก: BFS (หน้า 15) + min-heap ของ pair (หน้า 8) — สองอย่างที่ใช้เป็นแล้ว ประกอบกัน*

```cpp
const ll INF = 1e18;
vector<vector<pair<int,ll>>> adj(n + 1);        // {โหนดปลายทาง, น้ำหนัก}
// ตอนอ่าน edge: adj[a].push_back({b, w});  adj[b].push_back({a, w});

vector<ll> dist(n + 1, INF);
priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;  // min-heap {dist, node}
dist[s] = 0; pq.push({0, s});
while (!pq.empty()) {
    auto [d, u] = pq.top(); pq.pop();
    if (d > dist[u]) continue;         // ⚠ ตัวเก่าค้างใน heap — ไม่มีบรรทัดนี้ = TLE
    for (auto [v, w] : adj[u])
        if (dist[u] + w < dist[v]) {
            dist[v] = dist[u] + w;
            pq.push({dist[v], v});
        }
}
// จบ: dist[v] = ระยะสั้นสุด s→v,  ยัง INF = ไปไม่ถึง   O(m log n)
```

- เหมือน BFS ทุกอย่าง แค่เปลี่ยน queue → min-heap และ dist เป็นผลรวมน้ำหนัก
- ⚠ **edge ติดลบ = ห้ามใช้** (คำตอบผิดเงียบๆ) — โจทย์แข่งระดับเราแทบไม่มี edge ลบ ถ้ามีให้ข้ามข้อ
- dist ต้องเป็น `ll` เสมอ: 2e5 edge × 1e9 = เกิน int แน่นอน

| สถานการณ์ | ใช้ |
|---|---|
| ทุกก้าวราคาเท่ากัน | BFS (หน้า 15) |
| ก้าวมีน้ำหนัก (บวก), ถามจากจุดเดียว | Dijkstra |
| ถามทุกคู่ และ n ≤ 500 | Floyd-Warshall (หน้า 20) |

---

## หน้า 20 — Floyd-Warshall + Kruskal MST

**Floyd-Warshall — ระยะสั้นสุด "ทุกคู่" (n ≤ ~500 เท่านั้น, O(n³))**

```cpp
// d[i][j] เริ่มต้น: 0 ถ้า i==j • w ถ้ามี edge (edge ซ้ำเก็บ min) • INF ที่เหลือ
for (int k = 1; k <= n; k++)               // ⚠ k อยู่นอกสุดเสมอ สลับ = ผิด
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (d[i][k] < INF && d[k][j] < INF)     // ⚠ กัน INF + INF ล้น
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
```

3 บรรทัดจบ ไม่ต้องคิดอะไร — เห็น "ถามระยะหลายคู่ + n เล็ก" = เขียนเลย

**Kruskal — เชื่อมทุกโหนดด้วยต้นทุนรวมถูกสุด (MST)**

*ต่อยอดจาก: DSU (หน้า 16) — Kruskal คือ sort แล้ววน uni() แค่นั้น*

```cpp
// edges = vector<array<ll,3>> ของ {w, u, v}   ← น้ำหนักไว้หน้า sort ตรงๆ ได้เลย
sort(edges.begin(), edges.end());
dsu_init(n);
ll total = 0; int used = 0;
for (auto& [w, u, v] : edges)
    if (uni(u, v)) { total += w; used++; }      // uni คืน false = edge นี้สร้างวง ข้าม
if (used != n - 1) { /* กราฟไม่เชื่อมถึงกัน — เชื่อมครบไม่ได้ */ }
```

สัญญาณ: "สร้างถนน/เดินสายไฟให้ถึงกันหมด จ่ายน้อยสุด"

---

## หน้า 21 — DFS (ญาติของ BFS: ลุยลึกก่อน)

```cpp
// นับกลุ่มที่เชื่อมถึงกัน (connected components):
vector<int> comp(n + 1, 0);        // 0 = ยังไม่เคยไป
void dfs(int u, int c) {
    comp[u] = c;
    for (int v : adj[u]) if (!comp[v]) dfs(v, c);
}
int groups = 0;
for (int u = 1; u <= n; u++)
    if (!comp[u]) dfs(u, ++groups);
// ได้แถม: comp[u] บอกว่า u อยู่กลุ่มไหน → "u,v ถึงกันไหม" = comp[u] == comp[v]

// flood fill บนตาราง (นับ "เกาะ" / ระบายพื้นที่ติดกัน):
int R, C; vector<string> g;        // '.' เดินได้ '#' กำแพง
vector<vector<int>> vis(R, vector<int>(C, 0));
void fill(int r, int c) {
    if (r < 0 || r >= R || c < 0 || c >= C) return;
    if (g[r][c] == '#' || vis[r][c]) return;
    vis[r][c] = 1;
    fill(r+1, c); fill(r-1, c); fill(r, c+1); fill(r, c-1);
}
// นับเกาะ: วนทุกช่อง ถ้าเดินได้และยังไม่ vis → fill แล้วนับ +1
```

- ⚠ recursion ลึกเกิน ~1e5–1e6 = stack overflow → กราฟ/ตารางใหญ่ ใช้ BFS (หน้า 15) แทน ได้ผลเหมือนกันทุกงานในหน้านี้
- ใช้ DFS เมื่อ: ต้องการแค่ "ถึงกันไหม/กี่กลุ่ม/พื้นที่เท่าไหร่" (สั้นกว่า BFS) • ใช้ BFS เมื่อ: ต้องการ "ระยะ/จำนวนก้าว"

---

## หน้า 22 — Topological Sort (งานมีลำดับก่อน-หลัง)

*ต่อยอดจาก: BFS — โครงเดียวกันเป๊ะ แค่เปลี่ยนเงื่อนไขเข้าคิวเป็น "งานที่ไม่เหลือ prerequisite"*

```cpp
// edge u → v หมายถึง "u ต้องมาก่อน v"
vector<vector<int>> adj(n + 1);
vector<int> indeg(n + 1, 0);
// ตอนอ่าน: adj[u].push_back(v); indeg[v]++;

queue<int> q;
for (int u = 1; u <= n; u++) if (indeg[u] == 0) q.push(u);
vector<int> order;
while (!q.empty()) {
    int u = q.front(); q.pop();
    order.push_back(u);
    for (int v : adj[u])
        if (--indeg[v] == 0) q.push(v);
}
if ((int)order.size() < n) { /* มี cycle — เรียงลำดับไม่ได้ ("impossible") */ }
// order = ลำดับทำงานที่ถูกต้อง 1 แบบ (โจทย์ยอมรับแบบไหนก็ได้)
```

```cpp
// แถม: DP บนลำดับที่ได้ (เดินตาม order แล้ว dp ต่อได้เลย ไม่ต้องคิดลำดับ fill)
// ทางยาวสุดใน DAG:
vector<ll> dp(n + 1, 0);
for (int u : order)
    for (int v : adj[u]) dp[v] = max(dp[v], dp[u] + 1);
// นับจำนวนเส้นทาง s→ทุกโหนด: dp[s] = 1; แล้ว dp[v] = (dp[v] + dp[u]) % MOD
```

สัญญาณ: "วิชามี prerequisite" • "งาน A ก่อน B" • "เป็นไปได้ไหม" (= เช็ค cycle)

---

## หน้า 23 — Knapsack 0/1 + Subset Sum

*ต่อยอดจาก: Coin Combinations II (เหรียญนอก-ผลรวมใน) — ตัวเดียวกัน แต่ inner loop **ถอยหลัง***

```cpp
// 0/1 knapsack: ของ n ชิ้น {น้ำหนัก wt, มูลค่า val} ความจุ W — แต่ละชิ้นหยิบได้ครั้งเดียว
vector<ll> dp(W + 1, 0);           // dp[w] = มูลค่ามากสุดที่ความจุ w
for (int i = 0; i < n; i++)
    for (int w = W; w >= wt[i]; w--)        // ⚠ ถอยหลัง = ชิ้นนี้ใช้ได้ครั้งเดียว
        dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
// คำตอบ: dp[W]

// ทำไมถอยหลัง: เดินหน้า = dp[w-wt] อาจถูกชิ้น "นี้" อัปเดตไปแล้วในรอบเดียวกัน = หยิบซ้ำ
// เดินหน้า = หยิบซ้ำได้ไม่จำกัด (unbounded) — คือ Coin Comb II ที่เคยเขียนนั่นเอง

// subset sum: เซตตัวเลข สร้าง "ผลรวม" อะไรได้บ้าง (เช่น Money Sums)
vector<char> can(X + 1, 0); can[0] = 1;
for (ll c : a)
    for (int s = X; s >= c; s--)            // ถอยหลังเหมือนกัน (ตัวละครั้ง)
        if (can[s - c]) can[s] = 1;
// ตอบ: ทุก s ที่ can[s] == 1
// "แบ่งสองกองให้ใกล้กันสุด" = subset sum แล้วหา s ใกล้ ผลรวม/2 ที่ can[s]
```

สัญญาณ: "เลือกของภายใต้งบ/น้ำหนักจำกัด" • "สร้างค่า x ได้ไหม" • "แบ่งของสองกอง"
⚠ ใช้ได้เมื่อ W/X ≤ ~1e6 (dp ตามขนาดผลรวม ไม่ใช่จำนวนชิ้น)

---

## หน้า 24 — LCS / Edit Distance / LIS

*ต่อยอดจาก: 2D DP (Array Description) — state สองมิติ i,j = ตำแหน่งในสอง string*

```cpp
// LCS: ลำดับย่อยร่วมยาวสุดของ a, b (ไม่ต้องติดกัน)  O(nm) — n,m ≤ ~5000
vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
        dp[i][j] = (a[i-1] == b[j-1])              // ⚠ string index = i-1 (dp เลื่อน 1)
                 ? dp[i-1][j-1] + 1
                 : max(dp[i-1][j], dp[i][j-1]);
// คำตอบ: dp[n][m]

// edit distance (แก้ a เป็น b น้อยครั้งสุด: ลบ/เพิ่ม/แทนที่) — โครงเดียวกัน:
// dp[i][0] = i, dp[0][j] = j (base!)
// ตรงกัน → dp[i-1][j-1]  ไม่ตรง → 1 + min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]})
```

```cpp
// LIS: ลำดับย่อยเพิ่มขึ้นยาวสุด  O(n log n) — แค่ lower_bound ที่ใช้เป็นอยู่แล้ว
vector<ll> t;                      // t[k] = ตัวปลายเล็กสุดของลำดับยาว k+1
for (ll x : a) {
    auto it = lower_bound(t.begin(), t.end(), x);
    if (it == t.end()) t.push_back(x);
    else *it = x;
}
// คำตอบ = t.size()
// เพิ่มขึ้น "แท้" (< เท่านั้น) → lower_bound   เท่ากันได้ (≤) → เปลี่ยนเป็น upper_bound
// ⚠ t ไม่ใช่ลำดับจริง (ความยาวถูกอย่างเดียว) — โจทย์ขอตัวลำดับ = คนละเรื่อง
```

---

## หน้า 25 (หลังสุด — พลิกจากปกหลัง) — โจทย์หาอะไร → ใช้อะไร

| โจทย์ถาม / สัญญาณ | ใช้ | หน้า |
|---|---|---|
| n ≤ 11 / n ≤ 20 | brute force ทุกแบบ | 18 |
| "น้อยสุด/มากสุดที่ยังทำได้" + เช็คค่าเดียวง่าย | binary search on answer | 11 |
| subarray ติดกัน ผลรวม/เงื่อนไขตามที่กำหนด | two pointers (บวกล้วน) / prefix+map (มีลบ) | 12 |
| ถามผลรวมช่วงเดิมๆ หลายรอบ | prefix sum | 12 |
| เลือกกิจกรรม/ช่วงเวลา มากสุดไม่ชนกัน | sort ตามเวลาจบ + เก็บ cur | 13 |
| ต้องใช้กี่ห้อง / ซ้อนกันสูงสุดเท่าไหร่ | event sweep ±1 | 13 |
| แจกงานให้ k คน ได้มากสุด | sort จบ + multiset เวลาว่าง | 13 |
| "นับจำนวนวิธี" (mod 1e9+7) | counting DP, dp[0]=1 | 14 |
| ค่าน้อยสุด แล้ว greedy หา counterexample ได้ | DP min, dp[0]=0, INF guard | 14 |
| ก้าวน้อยสุด / ไปถึงไหม (เขาวงกต, กราฟ) | BFS | 15 |
| ทางสั้นสุด เมื่อก้าวมี "น้ำหนัก" (บวก) | Dijkstra | 19 |
| ทางสั้นสุดหลายคู่ + n ≤ 500 | Floyd-Warshall | 20 |
| เชื่อมทุกเมือง จ่ายรวมถูกสุด | Kruskal (sort + DSU) | 20 |
| นับเกาะ / กี่กลุ่ม / พื้นที่ติดกัน | DFS / flood fill | 21 |
| งานมีลำดับก่อน-หลัง / prerequisite / เช็ค cycle | toposort | 22 |
| ทางยาวสุด-นับเส้นทาง บนกราฟมีทิศไม่มีวง | toposort + DP | 22 |
| เลือกของภายใต้งบ/น้ำหนัก ชิ้นละครั้ง | 0/1 knapsack | 23 |
| สร้างผลรวม x ได้ไหม / แบ่งสองกอง | subset sum | 23 |
| ความคล้ายสอง string / แก้กี่ครั้ง | LCS / edit distance | 24 |
| ลำดับย่อยเพิ่มขึ้นยาวสุด | LIS (lower_bound) | 24 |
| เพิ่ม edge ทีละเส้น + ถาม "ถึงกันยัง" ระหว่างทาง | DSU | 16 |
| นับวิธีเลือก r จาก n | nCr mod (fact + inv) | 17 |
| หารลงตัว / เศษ / จำนวนเฉพาะ | gcd, sieve, modpow | 17 |
| ดึง min/max สลับกับ insert ตลอดเวลา | priority_queue / multiset | 8, 5 |
| ตามหลำดับล่าสุด / จับคู่เปิด-ปิด | stack | 7 |
| โจทย์เล่าเรื่องยาว input แปลก | แกะด้วย getline/stringstream | 10 |

*ทุกแถวชี้ไปหน้าที่มี code ในเล่มนี้ — หน้า 2–18 คือของที่ใช้เป็นแล้ว, หน้า 19–24 คือญาติใกล้ของมัน (แต่ละหน้าเขียนไว้ว่าต่อยอดจากอะไร)*
