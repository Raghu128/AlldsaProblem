<h2><a href="https://www.geeksforgeeks.org/problems/zigzag-tree-traversal/1">ZigZag Tree Traversal</a></h2><h3>Difficulty Level : Difficulty: Medium</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a binary tree with <strong>n</strong> nodes. Find the zig-zag level order traversal of the binary tree. <br></span><span style="font-size: 18px;">In zig zag traversal starting from the first level go from <strong>left to right</strong> for odd-numbered levels and <strong>right to left </strong>for even-numbered levels.</span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>  &nbsp; &nbsp; &nbsp;&nbsp;1
 &nbsp;  &nbsp; /&nbsp; &nbsp;\
     2&nbsp; &nbsp; 3
&nbsp;   / \    /   \
&nbsp;  4   5 6   7
<strong>Output:
</strong>1 3 2 4 5 6 7<br><strong>Explanation:</strong><br>For level 1 going left to right, we get traversal as {1}.<br>For level 2 going right to left, we get traversal as {3,2}.<br>For level 3 going left to right, we get traversal as {4,5,6,7}.<br>Merging all this traversals in single array we get {1,3,2,4,5,6,7}<br></span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:
</strong>  &nbsp; &nbsp; &nbsp; &nbsp; &nbsp;7
 &nbsp; &nbsp; &nbsp; &nbsp;/&nbsp; &nbsp; &nbsp;\
 &nbsp; &nbsp; &nbsp; 9&nbsp; &nbsp; &nbsp; 7
 &nbsp; &nbsp; /&nbsp; \&nbsp;     /&nbsp; &nbsp;
&nbsp;  &nbsp;8&nbsp; &nbsp;8&nbsp;  6&nbsp; &nbsp; &nbsp;
 &nbsp; /&nbsp; \
&nbsp; 10&nbsp; 9&nbsp;
<strong>Output:
</strong></span><span style="font-size: 18px;">7 7 9 8 8 6 9 10 <br><strong>Explanation:<br></strong>For level 1 going left to right, we get traversal as {7}.<br>For level 2 going right to left, we get traversal as {7,9}.<br>For level 3 going left to right, we get traversal as {8,8,6}.<br>For level 4 going right to left, we get traversal as {9,10}.<br></span><span style="font-size: 14pt;">Merging all this traversals in single array we get {7,7,9,8,8,6,9,10}.</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>zigZagTraversal()</strong> which takes the root node of the Binary Tree as its input and returns a list containing the node values as they appear in the zig-zag level-order traversal of the tree.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n).<br><strong>Expected Auxiliary Space:</strong> O(n).</span></p>
<p><span style="font-size: 18px;"><strong><strong>Constraints:</strong></strong><br>1 &lt;= n &lt;= 10<sup>5</sup></span></p></div><p><span style=font-size:18px><strong>Company Tags : </strong><br><code>Flipkart</code>&nbsp;<code>Amazon</code>&nbsp;<code>Microsoft</code>&nbsp;<code>Snapdeal</code>&nbsp;<code>FactSet</code>&nbsp;<code>Hike</code>&nbsp;<code>Walmart</code>&nbsp;<code>Cisco</code>&nbsp;<br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Traversal</code>&nbsp;<code>Tree</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;