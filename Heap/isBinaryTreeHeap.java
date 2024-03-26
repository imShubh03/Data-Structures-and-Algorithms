package Heap;

class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class isBinaryTreeHeap {
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;

        int ans = 1 + countNodes(root.left) + countNodes(root.right);
        return ans;
    }

    public boolean isCBT(TreeNode root, int index, int cnt) {
        // base case
        if (root == null)
            return true;

        if (index >= cnt) {
            return false;
        } else {
            boolean leftAns = isCBT(root.left, 2 * index + 1, cnt);
            boolean rightAns = isCBT(root.right, 2 * index + 2, cnt);

            return (leftAns && rightAns);
        }
    }

    public boolean isMinHeap(TreeNode root) {
        // base case and leaf node
        if (root == null || (root.left == null && root.right == null)) {
            return true;
        }

        // only left is present
        if (root.right == null) {
            return (root.val <= root.left.val);
        } else {
            // both left and right are present
            boolean left = isMinHeap(root.left);
            boolean right = isMinHeap(root.right);

            // Ensure that both children are not null before accessing their values
            if (root.left != null && root.right != null) {
                return (left && right && (root.val <= root.left.val && root.val <= root.right.val));
            } else {
                return false;
            }
        }
    }

    public boolean isCompleteTree(TreeNode root) {
        if (root == null)
            return true; // Check if root is null
        int index = 0;
        int totalCount = countNodes(root);
        return isCBT(root, index, totalCount) && isMinHeap(root);
    }

    public static void main(String[] args) {
        isBinaryTreeHeap solution = new isBinaryTreeHeap();

        // Create a binary tree
        TreeNode root = new TreeNode(1);
        root.left = new TreeNode(2);
        root.right = new TreeNode(3);
        root.left.left = new TreeNode(4);
        root.left.right = new TreeNode(5);
        root.right.left = null; // Comment out or remove this line if you want to test with a complete tree
        root.right.right = new TreeNode(7);

        // Check if the tree is a complete binary tree and a min-heap
        boolean isComplete = solution.isCompleteTree(root);
        System.out.println("Is Complete Tree: " + isComplete);

        boolean isHeap = solution.isMinHeap(root);
        System.out.println("Is Min Heap: " + isHeap);
    }
}
