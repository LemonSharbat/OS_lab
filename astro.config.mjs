import { defineConfig } from 'astro/config';

// GitHub project sites are hosted below /<repository-name>.
// GitHub Actions sets GITHUB_REPOSITORY as owner/repository.
const repository = process.env.GITHUB_REPOSITORY ?? '';
const [owner, repositoryName] = repository.split('/');
const isUserOrOrganizationSite = repositoryName?.endsWith('.github.io');
const base = process.env.GITHUB_ACTIONS === 'true' && repositoryName && !isUserOrOrganizationSite
  ? `/${repositoryName}/`
  : '/';

export default defineConfig({
  site: owner ? `https://${owner}.github.io` : 'https://example.github.io',
  base,
  trailingSlash: 'always',
  markdown: {
    // Markdown code fences use the same restrained GitHub-style palette.
    shikiConfig: { theme: 'github-dark' }
  }
});
