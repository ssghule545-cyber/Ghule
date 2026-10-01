// Fetch user posts and calculate basic statistics
async function analyzeUserPosts(userId) {
  const url = `https://jsonplaceholder.typicode.com/posts?userId=${userId}`;

  try {
    const response = await fetch(url);

    if (!response.ok) {
      throw new Error(`HTTP error! Status: ${response.status}`);
    }

    const posts = await response.json();

    // Transform and analyze data
    const summary = {
      totalPosts: posts.length,
      titles: posts.map((post) => post.title),
      averageBodyLength:
        posts.reduce((acc, post) => acc + post.body.length, 0) / posts.length,
      longestPost: posts.reduce((longest, current) =>
        current.body.length > longest.body.length ? current : longest
      ),
    };

    console.log(`--- Summary for User ${userId} ---`);
    console.log(`Total Posts: ${summary.totalPosts}`);
    console.log(`Average Body Characters: ${summary.averageBodyLength.toFixed(1)}`);
    console.log(`Longest Post Title: "${summary.longestPost.title}"`);

    return summary;
  } catch (error) {
    console.error("Failed to fetch or process posts:", error.message);
  }
}

// Run the function
analyzeUserPosts(1);
