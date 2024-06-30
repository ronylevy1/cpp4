//Roniki04@gmail.com

סקירה כללית : 
פרויקט זה מממש מבנה נתונים מסוג עץ k-ענפי גנרי עם פונקציות מעבר והצגה גרפית באמצעות C++. המבנה תומך בשיטות מעבר שונות, כולל חיפוש לעומק (DFS), חיפוש לרוחב (BFS), ומעברים ספציפיים לסדרים (pre-order, post-order, in-order). בנוסף, הפרויקט משתמש בספריית SFML להצגה גרפית של העץ.

היררכיית מחלקות :
Tree
מחלקת Tree היא מחלקה תבניתית שמייצגת עץ k-ענפי. היא מספקת שיטות להוספת צמתים, מעבר בעץ באמצעות אלגוריתמים שונים, והצגת העץ באמצעות SFML.

פרמטרים של תבנית:

T: סוג הנתונים המאוחסן בצמתים.
k: מספר הילדים שכל צומת יכול להכיל (ברירת המחדל היא 2 עבור עצים בינאריים).
חברים פרטיים:

Node<T>* rootTree: מצביע לצומת השורש של העץ.
sf::Font fontObj: אובייקט גופן של SFML לרינדור טקסט.
שיטות ציבוריות:

Tree(): בנאי שמאתחל את העץ וטוען את הגופן.
void add_root(Node<T>* root): מוסיף צומת שורש לעץ.
Node<T>* get_root(): מחזיר את צומת השורש של העץ.
void add_sub_node(Node<T>* parent, Node<T>* child): מוסיף צומת ילד לצומת הורה.
dfs<T> begin_pre_order(), dfs<T> end_pre_order(): מחזיר איטרטורים למעבר pre-order.
dfs<T> begin_post_order(), dfs<T> end_post_order(): מחזיר איטרטורים למעבר post-order.
dfs<T> begin_in_order(), dfs<T> end_in_order(): מחזיר איטרטורים למעבר in-order.
bfs<T> begin_bfs_scan(), bfs<T> end_bfs_scan(): מחזיר איטרטורים למעבר BFS.
dfs<T> begin_dfs_scan(), dfs<T> end_dfs_scan(): מחזיר איטרטורים למעבר DFS.
myHeap<T> MyHeap(): יוצר ומחזיר ייצוג של העץ כערימה.
void display(): מציג את העץ באמצעות SFML.
~Tree(): מוחק את העץ .
Node
מחלקת Node מייצגת צומת בעץ. היא מאחסנת את הנתונים ורשימת צמתים ילדים.

פרמטרים של תבנית:

T: סוג הנתונים המאוחסן בצומת.
חברים פרטיים:

T data: הנתונים המאוחסנים בצומת.
std::vector<Node<T>*> childrenNodes: וקטור של צמתים ילדים.
שיטות ציבוריות:

Node(const T& data): בנאי שמאתחל את הצומת עם נתונים.
void set_data(T data): מגדיר את הנתונים של הצומת.
T get_data() const: מחזיר את הנתונים של הצומת.
void add_child(Node<T>* child): מוסיף צומת ילד.
std::vector<Node<T>*>& get_childrenNodes(): מחזיר את הוקטור של צמתים ילדים.
מחלקות מעבר
מחלקות מעבר מספקות איטרטורים לשיטות מעבר שונות. כל מחלקת מעבר מממשת את האופרטורים  (++),  (*), והשוואה (!=, ==).

PreOrder
פרמטרים של תבנית:

T: סוג הנתונים המאוחסן בצמתים.
חברים פרטיים:

Node<T>* rootTree: שורש העץ.
std::stack<Node<T>*> stack: מחסנית למעבר.
שיטות ציבוריות:

preOrder(Node<T>* root): בנאי שמאתחל את המעבר.
preOrder& operator++(): אופרטור למעבר.
T& operator*(): אופרטור לגישה לנתוני הצומת.
bool operator!=(const preOrder& other) const: אופרטור השוואה.
bool operator==(const preOrder& other) const: אופרטור השוואה.
Node<T>* operator->(): אופרטור גישה לחבר.
PostOrder
פרמטרים של תבנית:

T: סוג הנתונים המאוחסן בצמתים.
חברים פרטיים:

Node<T>* rootTree: שורש העץ.
std::stack<Node<T>*> myStack: מחסנית למעבר.
שיטות ציבוריות:

postOrder(Node<T>* root): בנאי שמאתחל את המעבר.
postOrder& operator++(): אופרטור למעבר.
Node<T>& operator*(): אופרטור לגישה לנתוני הצומת.
bool operator!=(const postOrder& other) const: אופרטור השוואה.
bool operator==(const postOrder& other) const: אופרטור השוואה.
Node<T>* operator->(): אופרטור גישה לחבר.
myHeap
מחלקת myHeap יוצרת ייצוג של העץ כערימה.

פרמטרים של תבנית:

T: סוג הנתונים המאוחסן בצמתים.
חברים פרטיים:

std::vector<Node<T>*> heap: וקטור שמייצג את הערימה.
size_t index: אינדקס נוכחי בערימה.
שיטות ציבוריות:

myHeap(Node<T>* root): בנאי שמאתחל את הערימה מהעץ.
myHeap& operator++(): אופרטור למעבר בערימה.
Node<T>& operator*(): אופרטור לגישה לנתוני הצומת.
Node<T>* operator->(): אופרטור גישה לחבר.
bool operator!=(const myHeap& other) const: אופרטור השוואה.
bool operator==(const myHeap& other) const: אופרטור השוואה.
myHeap begin(): מחזיר את תחילת הערימה.
myHeap end(): מחזיר את סוף הערימה.
MyComplex
מחלקת MyComplex מייצגת מספר מרוכב ומספקת פעולות אריתמטיות בסיסיות.

חברים פרטיים:

double real: החלק הממשי של המספר המרוכב.
double imag: החלק המדומה של המספר המרוכב.
שיטות ציבוריות:

MyComplex(): בנאי ברירת מחדל.
MyComplex(double real, double imag): בנאי עם חלק ממשי ומדומה.
MyComplex(const MyComplex& other): בנאי העתקה.
double getReal() const: מחזיר את החלק הממשי.
double getImag() const: מחזיר את החלק המדומה.
MyComplex& operator=(const MyComplex& other): אופרטור השמה.
MyComplex operator+(const MyComplex& other) const: אופרטור חיבור.
MyComplex operator-(const MyComplex& other) const: אופרטור חיסור.
MyComplex operator*(const MyComplex& other) const: אופרטור כפל.
MyComplex operator/(const MyComplex& other) const: אופרטור חילוק.
bool operator==(const MyComplex& other) const: אופרטור שוויון.
bool operator!=(const MyComplex& other) const: אופרטור אי-שוויון.
bool operator>(const MyComplex& other) const: אופרטור גדול מ.
friend std::ostream& operator<<(std::ostream& os, const MyComplex& c): אופרטור הזרמת פלט.


SFML (Simple and Fast Multimedia Library): משתמשים בספרייה זו להצגה גרפית של העץ.
ספריית התקן של C++: כולל ספריות סטנדרטיות כמו <iostream>, <vector>, <stack>, ועוד.

// נעזרתי בchatgpt

